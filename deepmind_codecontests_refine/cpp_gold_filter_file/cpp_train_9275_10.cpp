#include <bits/stdc++.h>
using namespace std;
const int inf32 = 1e9 + 9;
const long long inf64 = 1e18 + 18;
const int N = 1e5 + 3, LG = 32;
int ar[N], n;
bool win[N], used[N];
bool dfs(int cur) {
  if (used[cur]) return win[cur];
  used[cur] = true;
  for (int i = cur + ar[cur]; i < n; i += ar[cur]) {
    if (ar[cur] < ar[i]) win[cur] |= !dfs(i);
  }
  for (int i = cur - ar[cur]; i >= 0; i -= ar[cur]) {
    if (ar[cur] < ar[i]) win[cur] |= !dfs(i);
  }
  return win[cur];
}
void Solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", ar + i);
  for (int i = 0; i < n; ++i) {
    if (dfs(i))
      cout << 'A';
    else
      cout << 'B';
  }
}
int main() {
  Solve();
  return 0;
}
