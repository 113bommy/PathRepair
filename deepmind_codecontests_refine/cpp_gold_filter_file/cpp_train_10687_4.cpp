#include <bits/stdc++.h>
using namespace std;
int cube(int a, int b) {
  int o = a;
  for (int i = 1; i < b; i++) {
    o *= a;
  }
  return o;
}
void testing_ifs() {
  bool isMale;
  string a, b;
  bool isTall;
  int i = 0;
  bool repeat = true;
  while (repeat == true) {
    while (a != "yes" && a != "no") {
      cout << "are you male? yes/no  " << i << '\n';
      cin >> a;
      i = i + 1;
      if (a == "yes") {
        isMale = true;
      } else
        isMale = false;
    }
    while (b != "yes" && b != "no") {
      if (isMale) {
        cout << "are you tall? yes/no\n";
        cin >> b;
        if (b == "yes") {
          isTall = true;
        } else
          isTall = false;
      } else {
        b = "no";
      }
    }
    if (isMale && isTall) {
      cout << "You Are alpha  Male\n";
    }
    if (isMale && !isTall) {
      cout << "You Are a short Male\n";
    }
    if (!isMale) cout << "You are beyta\n";
    cout << "do you want to repeat the program? Yes/No\n";
    string repeat;
    cin >> repeat;
    if (repeat == "no")
      break;
    else {
      a = "aaaaa";
      b = "bbbbb";
    }
  }
}
int getMax(int num1, int num2, int num3) {
  int result;
  if (num1 > num2 && num1 > num3) {
    result = num1;
  } else if (num2 > num1 && num2 > num3) {
    result = num2;
  } else
    result = num3;
  return result;
}
int stones() {
  int output = 0;
  int n;
  string s;
  cin >> n;
  cin >> s;
  int j = 0;
  char x = s[0];
  for (int i = 1; i < (s.length()); i++) {
    if (x == s[i]) {
      output++;
    }
    x = s[i];
  }
  cout << output;
  return 0;
}
int weather_this_DOESNT_WORK() {
  int outcome = 0;
  int n;
  cin >> n;
  vector<int> temps(n);
  vector<int> temps_from_input(n);
  vector<int>::iterator it, it2;
  int j = 0;
  int temps_iter = 0;
  for (it = temps.begin(); it != temps.end(); it++) {
    cin >> *it;
  }
  for (it = temps.begin(); it != temps.end(); it++, temps_iter++) {
    temps_from_input.push_back(*it);
  }
  for (int i = 0; i < n - 1; i++) {
    if (temps[i] != 0) {
      if (temps[i] > 0 && temps[i + 1] < 0) {
        if (i == 0) {
          outcome++;
          temps[i] = -1;
        }
        if (i == (n - 2) && (temps[i + 1] < 0)) {
          cout << "you lose1    " << i;
          outcome++;
          break;
        } else if (temps[i - 1] < 0) {
          outcome++;
        }
      } else if (temps[i] < 0 && temps[i + 1] > 0) {
        if (i == 0) {
          temps[i] = 1;
          outcome++;
        }
        if (i == (n - 2) && (temps[i + 1] > 0)) {
          cout << "you lose2    " << i;
          outcome++;
        } else if (temps[i - 1] > 0) {
          outcome++;
        }
      }
    } else {
      outcome++;
    }
  }
  cout << "    " << outcome;
  return 0;
}
int sets() {
  string name;
  set<char> letters;
  cin >> name;
  for (int i = 0; i < name.length(); i++) {
    letters.insert(name[i]);
  }
  if (letters.size() % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
  return 0;
}
int nanners() {
  int k;
  int n;
  int w;
  int tot_cost = 0;
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) {
    tot_cost = tot_cost + k * i;
  }
  if (tot_cost - n > 0)
    cout << tot_cost - n;
  else
    cout << 0;
  return 0;
}
int bears() {
  int a, b;
  cin >> a >> b;
  int i = 0;
  for (i = 0; a <= b; i++) {
    a = a * 3;
    b = b * 2;
  }
  cout << i;
  return 0;
}
int tram() {
  int n, a, b, max = 0, curr = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    curr = curr - a + b;
    max = std::max(max, curr);
  }
  cout << max;
  return 0;
}
int wierd_math() {
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < b; i++)
    if (a % 10 == 0) {
      a = a / 10;
    } else {
      a = a - 1;
    }
  cout << a;
  return 0;
}
int main() {
  wierd_math();
  return 0;
}
