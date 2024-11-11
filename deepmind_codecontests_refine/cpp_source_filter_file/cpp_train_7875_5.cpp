#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
const int C = 1e7;
int trie[C][2], minn[C];
int now = 100001;
int q, type, x, k, s;
vector<int> v[100007];
set<int> ss;
void Insert(int P, int X) {
  int nnow = P, tmp;
  vector<int> vv;
  for (int i = 16; i >= 0; i--) {
    vv.push_back(nnow);
    if (X & (1 << i))
      tmp = 1;
    else
      tmp = 0;
    if (trie[nnow][tmp] == 0) trie[nnow][tmp] = now++;
    nnow = trie[nnow][tmp];
  }
  minn[nnow] = X;
  reverse((vv).begin(), (vv).end());
  for (int i : vv) minn[i] = min(minn[trie[i][0]], minn[trie[i][1]]);
}
int Find(int P, int maxx, int X) {
  int nnow = P, ok = 0, ret = 0;
  for (int i = 16; i >= 0; i--) {
    int L = trie[nnow][0], R = trie[nnow][1], tmp = 0;
    if (!ok) {
      if (maxx & (1 << i)) {
        if (minn[nnow] > maxx) return -1;
        if (X & (1 << i)) {
          if (L == 0)
            nnow = R, tmp = 1;
          else
            nnow = L, ok = 1;
        } else {
          if (minn[R] > maxx)
            nnow = L, ok = 1;
          else
            nnow = R, tmp = 1;
        }
      } else {
        if (L == 0 || minn[nnow] > maxx) return -1;
        nnow = L;
      }
    } else {
      if (X & (1 << i)) {
        if (L != 0)
          nnow = L;
        else
          nnow = R, tmp = 1;
      } else {
        if (R != 0)
          nnow = R, tmp = 1;
        else
          nnow = L;
      }
    }
    ret = (ret | (tmp * (1 << i)));
  }
  return ret;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  trie[0][0] = trie[0][1] = minn[0] = inf;
  for (int i = 1; i <= 100000; i++)
    for (int j = i; j <= 100000; j += i) v[j].push_back(i);
  cin >> q;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> x;
      if (ss.find(x) != ss.end()) continue;
      ss.insert(x);
      for (int i : v[x]) Insert(i, x);
    } else if (type == 2) {
      cin >> x >> k >> s;
      if (s - x <= 0 || x % k != 0)
        cout << -1 << '\n';
      else
        cout << Find(k, s - x, k) << '\n';
    }
  }
}
