#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
map<int, vector<int>> mp;
map<int, int> gr;
int sz(int x, int s) {
  while (x) {
    x >>= 1;
    s++;
  }
  return s;
}
int grundy(int v) {
  if (gr.count(v)) return gr[v];
  if (v == 1) return 2;
  if (!v) return 1;
  int mex = 0;
  for (int i = 1; i < 30; i++) {
    if (!(v >> i)) break;
    mex |= (grundy((v >> i) | (v & ((1 << (i - 1)) - 1))));
  }
  return gr[v] = (~mex) & -(~mex);
}
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 2; j <= a / j; j++) {
      if (a % j) continue;
      int s = 0;
      while (a % j == 0) {
        s++;
        a /= j;
      }
      mp[j].push_back(s);
    }
    if (a != 1) mp[a].push_back(1);
  }
  int ans = 0;
  for (auto a : mp) {
    int bm = 0;
    for (int i : a.second) bm |= (1 << (i - 1));
    ans ^= sz(grundy(bm), -1);
  }
  if (ans)
    cout << "Mojtaba";
  else
    cout << "Arpa";
}
