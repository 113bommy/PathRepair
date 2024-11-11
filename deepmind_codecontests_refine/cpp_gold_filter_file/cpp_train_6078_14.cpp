#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000000 + 7;
int n, k, p[9];
int ans, used[9];
int t[] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2097152};
void check() {
  int cur = 0;
  memset(used, 0, sizeof(used));
  while (1) {
    cur = p[cur];
    if (used[cur]) break;
    used[cur] = 1;
  }
  if (!used[0]) return;
  for (int i = 1; i < k; i++) {
    memset(used, 0, sizeof(used));
    cur = i;
    while (1) {
      cur = p[cur];
      if (used[cur]) break;
      used[cur] = 1;
    }
    if (!used[0]) return;
  }
  ans++;
}
void dfs(int i) {
  if (i == k) {
    check();
    return;
  }
  for (int j = 0; j < k; j++) {
    p[i] = j;
    dfs(i + 1);
  }
}
int main() {
  cin >> n >> k;
  ans = t[k];
  long long a = n - k;
  long long b = n - k;
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    b >>= 1;
    a = a * a % mod;
  }
  c = c * ans % mod;
  cout << c << endl;
  return 0;
}
