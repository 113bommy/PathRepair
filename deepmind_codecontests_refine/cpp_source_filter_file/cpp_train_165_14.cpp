#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void prn(Arg1&& arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void prn(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  prn(args...);
}
template <typename Arg1>
void prs(Arg1&& arg1) {
  cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void prs(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  prs(args...);
}
template <typename Arg1>
void read(Arg1&& arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1&& arg1, Args&&... args) {
  cin >> arg1;
  read(args...);
}
inline void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int tc = 1; tc <= t; ++tc) {
    solve();
  }
  return 0;
}
const int N = 2e5 + 1, M = 30;
int arr[N], nxt[N][M];
int n;
map<int, vector<int> > idxs;
int getNext(int val, int idx) {
  if (!idxs.count(val)) return n + 1;
  vector<int>& vec = idxs[val];
  auto it = lower_bound(vec.begin(), vec.end(), idx);
  if (it == vec.end()) return n + 1;
  return *it;
}
int getNewBit(int val, int idx) {
  int mn = n + 1;
  for (int i = 0; i < M; ++i) {
    if ((val >> i) & 1) continue;
    mn = min(mn, nxt[idx][i]);
  }
  return mn;
}
inline void solve() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(arr[i]);
    idxs[arr[i]].push_back(i);
  }
  for (int i = 0; i < M; ++i) {
    nxt[n + 1][i] = n + 1;
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j < M; ++j) {
      nxt[i][j] = nxt[i + 1][j];
      if ((arr[i] >> j) & 1) {
        nxt[i][j] = i;
      }
    }
  }
  long long ans = 0;
  for (int st = 1; st <= n; ++st) {
    long long cur = 0, idx = st, tmp = 0;
    (st);
    while (idx <= n) {
      cur |= arr[idx];
      int i1 = getNext(cur, idx);
      int i2 = getNewBit(cur, idx);
      if (i1 <= idx) {
        idx = i2;
        continue;
      }
      if (i1 < i2) {
        ans += i1 - idx;
        idx = i1;
        continue;
      }
      tmp += i2 - idx;
      idx = i2;
    }
    (st, tmp);
    ans += tmp;
  }
  prn(ans);
}
