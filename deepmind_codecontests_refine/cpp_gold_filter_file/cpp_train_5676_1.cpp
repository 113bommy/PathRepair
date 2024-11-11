#include <bits/stdc++.h>
using namespace std;
int n, A, cmax, cmin;
unsigned long long int m;
long long int sum[100010];
pair<int, int> a[100010];
int readint() {
  char cc = getchar();
  while (cc < '0' || cc > '9') {
    cc = getchar();
  }
  int ans = 0;
  while (cc >= '0' && cc <= '9') {
    ans = ans * 10 + cc - '0';
    cc = getchar();
  }
  return ans;
}
pair<long long int, long long int> getmin(long long int p, int lv) {
  int l = lv - 1, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (1ll * (n - mid) * (a[mid].first) < sum[n] - sum[mid] + p)
      r = mid;
    else
      l = mid;
  }
  long long int used = (1ll * a[r].first * (n - r)) - (sum[n] - sum[r]);
  long long int rem = p - used;
  if (rem > 0 && r != n)
    return {a[r].first + (1ll * rem) / (n - r), r};
  else if (r == n)
    return {0, n};
  else
    return {a[r].first, r};
}
int main() {
  scanf("%d %d %d %d %I64d", &n, &A, &cmax, &cmin, &m);
  for (int i = 0; i < n; i++) a[i].first = readint(), a[i].second = i;
  sort(a, a + n, std::greater<pair<int, int> >());
  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i].first;
  int maxrt = 0, rt = 0, lt = n, ltval = 0;
  long long int val = 0;
  for (int i = 1; i < n + 1; i++) {
    if (1ll * i * A < sum[i] + m) maxrt++;
  }
  int minv = INT32_MAX;
  for (int j = 0; j < n; ++j) {
    if (a[j].first == A) val += cmax;
    if (a[j].first < minv) minv = a[j].first;
  }
  val += 1ll * minv * cmin;
  for (int i = maxrt; i >= 0; i--) {
    long long int tval = i * cmax;
    long long int used = 1ll * i * A - sum[i];
    long long int rem = m - used;
    pair<long long int, long long int> minn = getmin(rem, i);
    if (minn.first >= A) {
      minn.first = A;
      tval = (n - minn.second) * cmax;
    }
    tval += minn.first * cmin;
    if (tval > val) rt = i, lt = minn.second, val = tval, ltval = minn.first;
  }
  int temp[100010];
  for (int i = 0; i < n; i++) temp[a[i].second] = a[i].first;
  for (int i = 0; i < rt; i++) temp[a[i].second] = A;
  for (int i = lt; i < n; i++) temp[a[i].second] = ltval;
  printf("%I64d\n", val);
  for (int i = 0; i < n; i++) printf("%d ", temp[i]);
  return 0;
};
