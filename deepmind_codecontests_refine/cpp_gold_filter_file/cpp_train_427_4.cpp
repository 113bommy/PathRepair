#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long c[maxn], d[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &d[i]);
  for (int i = n; i > 0; i--) c[i] = c[i] - c[i - 1];
  for (int i = n; i > 0; i--) d[i] = d[i] - d[i - 1];
  sort(c + 1, c + n);
  sort(d + 1, d + n);
  for (int i = 0; i < n; i++) {
    if (c[i] != d[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
