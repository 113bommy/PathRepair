#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
const double eps = 1e-9;
int __ = 1, kase = 0;
int cnt[30];
string s;
void init() {}
void read() { cin >> s; }
void solve() {
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 25; i >= 0; i--) {
    if (cnt[i]) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << (char)(i + 'a');
      }
      cout << endl;
      break;
    }
  }
}
int main() {
  while (__--) {
    init();
    read();
    solve();
  }
  return 0;
}
