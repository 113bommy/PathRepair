#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
  cout << "YES\n";
  return;
}
void no() {
  cout << "NO\n";
  return;
}
void out(long long int n) {
  cout << n << endl;
  return;
}
void outs(string str) {
  cout << str << endl;
  return;
}
void init() {}
int val(char c) {
  if (c == 'q')
    return 9;
  else if (c == 'r')
    return 5;
  else if (c == 'b' || c == 'n')
    return 3;
  else if (c == 'p')
    return 1;
  return 0;
}
void solve(int case_no) {
  string str;
  int a1 = 0, a2 = 0;
  for (int i = 0; i < 8; i++) {
    cin >> str;
    for (int j = 0; j < 8; j++) {
      if (isupper(str[j])) {
        a1 += val(tolower(str[j]));
      } else if (islower(str[j])) {
        a2 += val(str[j]);
      }
    }
  }
  if (a1 > a2)
    outs("White");
  else if (a1 < a2)
    outs("Black");
  else
    outs("Draw");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  init();
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
}
