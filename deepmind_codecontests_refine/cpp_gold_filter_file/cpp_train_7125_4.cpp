#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const long long LINF = 1e18;
const double pi = 3.1415926535;
const double EPS = 1e-9;
int n;
vector<int> a(MAXN);
vector<int> len(MAXN, 0);
vector<int> reverseLen(MAXN, 0);
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i == 0 || a[i] <= a[i - 1])
      len[i] = 1;
    else
      len[i] = len[i - 1] + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || a[i] >= a[i + 1])
      reverseLen[i] = 1;
    else
      reverseLen[i] = reverseLen[i + 1] + 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    if (i == 0)
      l = 0;
    else
      l = len[i - 1];
    if (i == n - 1)
      r = 0;
    else
      r = reverseLen[i + 1];
    if (a[i - 1] + 1 < a[i + 1]) {
      ans = max(r + l + 1, ans);
    } else {
      ans = max(ans, max(r, l) + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
