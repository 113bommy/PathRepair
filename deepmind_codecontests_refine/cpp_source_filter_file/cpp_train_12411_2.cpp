#include <bits/stdc++.h>
std::string flower;
std::string quest[200];
std::string answer;
std::string my = "";
std::string O = "";
std::string H = "";
std::string C = "";
std::string Z = "";
std::string first[8] = {"CH", "CO", "HC", "HO", "CCC", "HHH", "OOO", "OOCC"};
int int_answ[60];
float en = 0;
int try_num = 0;
int quest_num = 0;
int my_len = 0;
int my_pos = 0;
int fl_len = 0;
void clear() {
  for (int i = 0; i < my.length(); i++) {
    switch (my[i]) {
      case 'C':
        O[i] = ' ';
        H[i] = ' ';
        break;
      case 'H':
        O[i] = ' ';
        C[i] = ' ';
        break;
      case 'O':
        C[i] = ' ';
        H[i] = ' ';
        break;
    }
  }
  std::string s;
  int index;
  int le;
  for (int i = 0; i < quest_num; i++) {
    le = quest[i].length();
    {
      s = "*";
      s += quest[i].substr(1, le - 1);
      index = 0;
      do {
        index = my.find(s, index);
        if (index == -1) break;
        switch (quest[i][0]) {
          case 'C':
            C[index] = '-';
            break;
          case 'H':
            H[index] = '-';
            break;
          case 'O':
            O[index] = '-';
            break;
        }
        index++;
      } while (index != 0);
      s = quest[i].substr(0, le - 1);
      ;
      s += "*";
      index = 0;
      do {
        index = my.find(s, index);
        if (index == -1) break;
        index++;
        switch (quest[i][le - 1]) {
          case 'C':
            C[index + le - 2] = '-';
            break;
          case 'H':
            H[index + le - 2] = '-';
            break;
          case 'O':
            O[index + le - 2] = '-';
            break;
        }
      } while (index != 0);
    }
  }
  for (int i = 0; i < my.length(); i++) {
    if ((O[i] == 'O') && (H[i] != 'H') && (C[i] != 'C')) my[i] = 'O';
    if ((O[i] != 'O') && (H[i] == 'H') && (C[i] != 'C')) my[i] = 'H';
    if ((O[i] != 'O') && (H[i] != 'H') && (C[i] == 'C')) my[i] = 'C';
  }
  int z;
  z = 0;
  for (int i = 0; i < my.length(); i++) {
    z = (O[i] == 'O') + (C[i] == 'C') + (H[i] == 'H');
    Z[i] = z + '0';
  }
}
void max_not_asterisk() {
  int max_len = 0;
  int max_pos = 0;
  int cur_len = 0;
  int cur_pos = 0;
  char prev_c = '\0';
  char cur_c = '\0';
  int le = my.length();
  for (int i = 0; i < le; i++) {
    cur_c = my[i];
    if (cur_c != '*') {
      if (prev_c == '*') {
        cur_pos = i;
        cur_len = 1;
      } else {
        cur_len++;
      }
    }
    prev_c = cur_c;
  }
  if (max_len < cur_len) {
    max_len = cur_len;
    max_pos = cur_pos;
  }
  my_pos = max_pos;
  my_len = max_len;
}
void next_request() {
  int pos = 0;
  std::string to_serv;
  bool prev = true;
  char sym = '\0';
  if (my_len < 2)
    if (try_num == 7) {
      my = "OOHH";
      my_len = fl_len;
      return;
    } else
      to_serv = first[try_num++];
  else {
    if (((my_pos > 0) && (Z[my_pos - 1] <= Z[my_pos + my_len])) ||
        ((my_pos + my_len) == fl_len)) {
      pos = my_pos - 1;
      prev = true;
    } else {
      pos = my_pos + my_len;
      prev = false;
    }
    if (O[pos] == 'O')
      sym = 'O';
    else if (H[pos] == 'H')
      sym = 'H';
    else
      sym = 'C';
    to_serv = my.substr(my_pos, my_len);
    if (prev)
      to_serv = sym + to_serv;
    else
      to_serv = to_serv + sym;
  }
  quest[quest_num++] = to_serv;
  printf("? %s\n", to_serv.c_str());
  fflush(stdout);
  std::cin >> int_answ[0];
  for (int i = 1; i <= int_answ[0]; i++) {
    std::cin >> int_answ[i];
    my.replace(int_answ[i] - 1, quest[quest_num - 1].length(),
               quest[quest_num - 1]);
  }
  clear();
  clear();
  max_not_asterisk();
}
int main() {
  int tt;
  int ok;
  std::cin >> tt;
  for (int t = 0; t < tt; t++) {
    std::cin >> fl_len;
    try_num = 0;
    my_len = 0;
    my_pos = 0;
    quest_num = 0;
    en = 0;
    my = "";
    O = "";
    H = "";
    C = "";
    Z = "";
    for (int i = 0; i < fl_len; i++) {
      my += "*";
      O += "O";
      H += "H";
      C += "C";
      Z += "3";
    }
    do {
      next_request();
    } while (my_len < fl_len);
    printf("! %s\n", my.c_str());
    fflush(stdout);
    std::cin >> ok;
    if (ok == 0) break;
  }
}
