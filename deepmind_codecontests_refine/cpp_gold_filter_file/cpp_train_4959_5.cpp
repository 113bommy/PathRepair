#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5, M = 1e6 + 5;
int n, a[N], mk[M], vis[M];
vector<int> b;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vis[a[i]] = 1;
  for (int i = 1; i <= n; i++) {
    b.push_back(a[1]);
    b.push_back(a[i]);
  }
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (a[i] % a[1]) flag = false;
  if (flag) {
    printf("%d\n", b.size());
    for (int i = 0; i < b.size(); i++) printf("%d ", b[i]);
  } else
    printf("-1\n");
  return 0;
}
