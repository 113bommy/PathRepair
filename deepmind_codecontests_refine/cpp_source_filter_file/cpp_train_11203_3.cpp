#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n;
int b[N], ans[N];
pair<int, int> a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  b[n + 1] = b[1];
  for (int i = 1; i <= n; i++) {
    a[i] = make_pair(-b[i] - b[i + 1], i - 1);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) ans[a[i].second] = i - 1;
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}
