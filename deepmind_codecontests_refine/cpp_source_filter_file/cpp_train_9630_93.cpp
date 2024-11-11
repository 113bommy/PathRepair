#include <bits/stdc++.h>
using namespace std;
void _591A() {
  double length, p, q;
  cin >> length >> p >> q;
  double time = length / (p + q);
  cout << time * p << endl;
}
void _591B() {
  char tr[26];
  char rev_tr[26];
  for (int i = 0; i < 26; i++) {
    tr[i] = -1;
    rev_tr[i] = -1;
  }
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  char prev, next;
  for (int i = 0; i < m; i++) {
    cin >> prev >> next;
    if (prev == next) {
      continue;
    }
    cout << "cur: " << prev << " " << next << endl;
    if (rev_tr[prev - 'a'] != -1) {
      cout << "zde" << endl;
      cout << "rev_tr: " << (int)rev_tr[prev - 'a'] << endl;
      tr[rev_tr[prev - 'a']] = next - 'a';
      rev_tr[next - 'a'] = rev_tr[prev - 'a'];
      rev_tr[prev - 'a'] = 0;
    } else {
      tr[prev - 'a'] = next - 'a';
      rev_tr[next - 'a'] = prev - 'a';
    }
    if (rev_tr[next - 'a'] != -1) {
      cout << "zde" << endl;
      cout << "rev_tr: " << (int)rev_tr[next - 'a'] << endl;
      tr[rev_tr[next - 'a']] = prev - 'a';
      rev_tr[prev - 'a'] = rev_tr[next - 'a'];
      rev_tr[next - 'a'] = 0;
    } else {
      tr[next - 'a'] = prev - 'a';
      rev_tr[prev - 'a'] = next - 'a';
    }
    for (int i = 0; i < 26; i++) {
      if (tr[i] != -1) {
        cout << (char)(i + 'a') << ": " << (char)(tr[i] + 'a') << endl;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (rev_tr[i] != -1) {
        cout << "reverse " << (char)(i + 'a') << ": " << (char)(rev_tr[i] + 'a')
             << endl;
      }
    }
  }
}
char is_letter_in_tr(char* tr, char* letter) {
  for (int i = 0; i < 26; i++) {
    if (tr[i] == *letter) {
      return i;
    }
  }
  return -1;
}
void _591B_2() {
  char tr[26];
  for (int i = 0; i < 26; i++) {
    tr[i] = -1;
  }
  int n, m;
  cin >> n >> m;
  char* str = new char[n + 1];
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    str[i] = s[i];
  }
  str[n] = '\0';
  char next, prev;
  char next_in_value, prev_in_value;
  for (int i = 0; i < m; i++) {
    cin >> prev >> next;
    prev -= 'a';
    next -= 'a';
    if (prev == next) continue;
    prev_in_value = is_letter_in_tr(tr, &prev);
    next_in_value = is_letter_in_tr(tr, &next);
    if (prev_in_value != -1) {
      tr[prev_in_value] = next;
    } else {
      tr[prev] = next;
    }
    if (next_in_value != -1) {
      tr[next_in_value] = prev;
    } else {
      tr[next] = prev;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (tr[i] == -1) {
      tr[i] = i;
    }
    tr[i] += 'a';
  }
  for (int i = 0; i < n; i++) {
    cout << tr[str[i] - 'a'];
  }
  cout << endl;
}
void _592A() {
  bool white[8] = {false}, black[8] = {false};
  char board[8][8];
  int best_white = 10, best_black = 10;
  char c;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c;
      board[i][j] = c;
      if (c == 'W') {
        if (black[j] == true) {
        } else {
          if (i + 1 < best_white) best_white = i + 1;
        }
      } else if (c == 'B') {
        black[j] = true;
      }
    }
  }
  for (int i = 7; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      if (board[i][j] == 'B') {
        if (white[j] == true) {
        } else {
          if (8 - i < best_black) {
            best_black = 8 - i;
          }
        }
      } else if (board[i][j] == 'W') {
        white[j] = true;
      }
    }
  }
  if (best_white <= best_black) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
void _592B() {
  int n;
  cin >> n;
  cout << (n - 2) * (n - 2) << endl;
  ;
}
int main(int argc, char** argv) {
  _592B();
  return 0;
}
