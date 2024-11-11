#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6;
long long int n, m;
vector<long long int> v(N);
bool check(long long int days) {
  long long int pages = 0, k = 0;
  for (long long int i = 0, j = 0; j < n; i++, j++) {
    pages += max(0ll, v[j] - k);
    if (i + 1 == days) i = -1, k++;
  }
  return pages >= m;
}
int32_t main() {
  scanf("%lld", &n);
  scanf("%lld", &m);
  long long int sum = 0;
  for (long long int i = 0; i < n; ++i) {
    scanf("%lld", &v[i]);
    sum += v[i];
  }
  if (sum < m) {
    printf("-1");
    return 0;
  }
  sort(v.begin(), v.end(), greater<long long int>());
  long long int ans = 1e16;
  long long int low = 1;
  long long int high = n;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  printf("%lld", ans);
  return 0;
}
