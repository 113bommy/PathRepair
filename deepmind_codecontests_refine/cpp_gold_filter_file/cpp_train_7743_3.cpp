#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MIN = -1e9, MAX = 1e9, MOD = 1e9 + 7;
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
void solve(int case_no) {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '#')
      cnt++;
    else
      cnt = 0;
    if (cnt >= k) return no();
  }
  yes();
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
