#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
int l[maxn], r[maxn], pos[maxn], b[maxn];
int N;
int lowbit(int x) { return x & (-x); }
void add(int x, int val) {
  for (int i = x; i <= N; i += lowbit(i)) b[i] += val;
}
int get(int x) {
  int ret = 0;
  for (int i = x; i; i -= lowbit(i)) ret += b[i];
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  N = n + m;
  for (int i = 1; i <= n; i++)
    pos[i] = n - i + 1, l[i] = i, r[i] = i, add(i, 1);
  for (int i = 0, j = n + 1; i < m; i++, j++) {
    int x;
    cin >> x;
    l[x] = 1;
    r[x] = max(r[x], 1 + get(j - 1) - get(pos[x]));
    add(pos[x], -1);
    add(j, 1);
    pos[x] = j;
  }
  for (int i = 1; i <= n; i++) {
    r[i] = max(r[i], 1 + get(N) - get(pos[i]));
  }
  for (int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << '\n';
}
