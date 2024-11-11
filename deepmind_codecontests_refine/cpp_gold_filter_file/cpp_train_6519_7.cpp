#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
set<int> S;
int n, s1, s2, a[N];
int chk(int x) {
  S.clear();
  S.insert(s1);
  for (int i = 1; i <= n; i++) {
    if (abs(a[i - 1] - a[i]) <= x) S.insert(a[i - 1]);
    while (S.size() && abs(a[i] - *S.begin()) > x) S.erase(S.begin());
    while (S.size() && abs(a[i] - *S.rbegin()) > x) S.erase(*S.rbegin());
    if (!S.size()) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[0] = s2;
  int l = abs(s2 - s1), r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    if (chk(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
