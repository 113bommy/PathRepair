#include <bits/stdc++.h>
using namespace std;
int n;
int A[2005], B[2005];
int f[2005];
vector<pair<int, int> > ans;
bool notsorted() {
  for (int i = 1; i <= n; i++) {
    if (f[i] != i) return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int j = 1; j <= n; j++) scanf("%d", &B[j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i] == B[j]) {
        f[i] = j;
        break;
      }
    }
  }
  int res = 0;
  while (notsorted()) {
    int mins = 1e9;
    int a, b;
    for (int i = 1; i <= n; i++) {
      if (f[i] != i) {
        a = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (f[i] == a) {
        b = i;
        break;
      }
    }
    res += b - a;
    for (int i = b - 1; i >= a; i--) {
      if (f[i] > f[b] && f[i] != i) {
        swap(f[i], f[b]);
        ans.push_back(make_pair(i, b));
        b = i;
      }
    }
  }
  printf("%d\n", res);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
