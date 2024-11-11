#include <bits/stdc++.h>
using namespace std;
vector<float> a, b;
int n, m, cnt = 0;
bool f(float mid) {
  float n1, n2;
  for (int i = 0; i < n - 1; ++i) {
    n1 = (m + mid) / (a[i]);
    if (mid - n1 < 0) return false;
    mid -= n1;
    n2 = (m + mid) / (b[i + 1]);
    if (mid - n2 < 0) return false;
    mid -= n2;
  }
  n1 = (m + mid) / a[n - 1];
  if (mid - n1 < 0) return false;
  mid -= n1;
  n2 = (m + mid) / (b[0]);
  if (mid - n2 < 0) return false;
  return true;
}
float solve() {
  float s = 0, e = 1000000001, ans = 1000000001, mid;
  while (abs(s - e) >= 0.00001) {
    mid = (s + e) / 2;
    if (f(mid)) {
      ans = mid;
      e = mid - 0.000001;
    } else
      s = mid + 0.000001;
    if (cnt >= 1000) return mid;
    ++cnt;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  scanf("%d%d", &n, &m);
  a = b = vector<float>(n);
  for (int i = 0; i < n; ++i) scanf("%f", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%f", &b[i]);
  if (f(2000000000) == false)
    printf("-1");
  else
    printf("%.6f", solve());
}
