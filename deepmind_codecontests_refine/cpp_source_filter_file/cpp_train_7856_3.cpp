#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 7 + 3;
unordered_map<char, int> dict = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
int n, m, k;
string s, t;
bitset<MAXN> b[4], ans;
void make(char c, int p) {
  int l = -1;
  for (int i = 0; i < (int)(n); i++) {
    if (s[i] == c) {
      l = max(l + 1, i - k);
      for (; l < min(n, i + k + 1); l++) {
        b[p][l] = 1;
      }
      l--;
    }
  }
}
void init() {
  cin >> n >> m >> k;
  cin >> s >> t;
  for (auto i : dict) {
    make(i.first, i.second);
  }
}
void solve() {
  int cnt = 0;
  for (int i = 0; i < (int)(n); i++) {
    ans[i] = 1;
  }
  for (int i = 0; i < (int)(m); i++) {
    ans &= b[dict[t[i]]] >> i;
  }
  for (int i = 0; i < (int)(n); i++) {
    cnt += ans[i];
  }
  cout << cnt << endl;
}
int main() {
  init();
  solve();
  return 0;
}
