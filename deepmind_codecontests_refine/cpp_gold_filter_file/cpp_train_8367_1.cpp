#include <bits/stdc++.h>
using namespace std;
const int N = 200009;
int a[N], b[N], c[N], p[N], id[N];
int n, m;
inline int lowbit(int f) { return f & (-f); }
int sum(int f) {
  int ans = 0;
  for (int i = f; i > 0; i -= lowbit(i)) {
    ans += c[i];
  }
  return ans;
}
void add(int f, int g) {
  for (int i = f; i <= m; i += lowbit(i)) {
    c[i] += g;
  }
}
int main() {
  scanf("%d", &n);
  m = n * 2;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    p[a[i]] = b[i];
    p[b[i]] = a[i];
    id[a[i]] = id[b[i]] = i;
  }
  long long a1 = 0;
  long long a2 = 0;
  for (int i = 1; i <= m; i++) {
    if (p[i] > i) continue;
    int ID = id[i];
    int x = sum(i) - sum(p[i] - 1);
    int z = i - p[i] - 1 - x * 2;
    add(p[i], 1);
    long long y = n - 1 - x - z;
    a1 += z * (x + y);
    a2 += x * y;
  }
  long long nn = n;
  long long aa = nn * (nn - 1) * (nn - 2) / 6;
  cout << aa - a1 / 2 - a2 << endl;
  return 0;
}
