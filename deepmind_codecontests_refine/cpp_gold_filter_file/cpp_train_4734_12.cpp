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
void init() {}
bool pp(int n) {
  for (int i = 2; i <= floor(sqrt(n)); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool vow(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
void solve(int case_no) {
  string str;
  getline(cin, str);
  int ptr;
  for (int i = str.length() - 1; i >= 0; i--) {
    if (isalpha(str[i])) {
      ptr = i;
      break;
    }
  }
  return (vow(tolower(str[ptr])) ? yes() : no());
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
