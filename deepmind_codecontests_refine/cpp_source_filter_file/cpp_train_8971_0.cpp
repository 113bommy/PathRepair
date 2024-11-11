#include <bits/stdc++.h>
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < 48) c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
const int maxn = 2e5 + 10;
int n, m, A[maxn], mp[maxn], lef[maxn], rig[maxn];
int par[maxn];
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void solve(int *ans) {
  for (int i = (1), iend = (n + 1); i <= iend; ++i) par[i] = i, mp[i] = i;
  int delta = 0;
  for (int i = (1), iend = (m); i <= iend; ++i) {
    int pos = A[i];
    delta++;
    int &x = mp[pos + delta];
    int &y = mp[pos + delta + 1];
    if (!x) continue;
    if (!y) {
      y = x, x = 0;
    } else {
      par[find(x)] = find(y), x = 0;
    }
  }
  for (int i = (1), iend = (n + m); i <= iend; ++i) {
    ans[mp[i]] = max(1, i - m);
  }
  for (int i = (1), iend = (n); i <= iend; ++i) {
    ans[i] = ans[find(i)];
  }
}
int main() {
  cin >> n >> m;
  if (n == 1) return puts("0"), 0;
  for (int i = (1), iend = (m); i <= iend; ++i) A[i] = read();
  solve(lef);
  for (int i = (1), iend = (m); i <= iend; ++i) A[i] = n - A[i] + 1;
  solve(rig);
  reverse(rig + 1, rig + n + 1);
  for (int i = (1), iend = (n); i <= iend; ++i) rig[i] = n - rig[i] + 1;
  long long ans = 0;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    ans += rig[i] - lef[i] + 1 + (lef[i] > 1) + (rig[i] < n);
  }
  cout << ans << endl;
  return 0;
}
