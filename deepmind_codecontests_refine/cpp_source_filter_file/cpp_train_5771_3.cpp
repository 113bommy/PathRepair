#include <bits/stdc++.h>
using namespace std;
inline int max(int a, int b) { return a < b ? b : a; }
inline int min(int a, int b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
inline long long min(long long a, long long b) { return a > b ? b : a; }
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
pair<int, int> arr[N];
int a[N], n, k;
char s[2000];
long long ans = INF;
vector<long long> p, q;
void calc(int zz) {
  p.clear();
  q.clear();
  int nd = zz, s = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i].first > nd || arr[i].first < nd - 1)
      q.push_back(arr[i].second);
    else
      p.push_back(arr[i].second);
    if (arr[i].first < nd - 1) s++;
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  for (int i = 0; i < p.size(); ++i)
    if (i != 0) p[i] += p[i - 1];
  for (int i = 0; i < q.size(); ++i)
    if (i != 0) q[i] += q[i - 1];
  if (q.size() >= nd) {
    long long x = q[nd - 1];
    if (s >= k) {
      ans = min(ans, x);
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    if (q.size() < nd - i - 1) continue;
    long long x = p[i];
    if (nd - i - 2 >= 0) x += q[nd - i - 2];
    if (s + i + 1 >= k) ans = min(ans, x);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  k--;
  if (k == n) {
    printf("0\n");
    exit(0);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &arr[i].first, &arr[i].second);
    arr[i].first *= -1;
    arr[i].second *= -1;
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; ++i) {
    arr[i].first *= -1, arr[i].second *= -1;
    a[i] = arr[i].second;
  }
  sort(a, a + n);
  if (arr[k].first >= n) {
    printf("-1\n");
    return 0;
  }
  if (arr[k].first == n) {
    long long x = 0;
    for (int i = 0; i < n; ++i) x += arr[i].second;
    printf("%lld\n", x);
    return 0;
  }
  int pp = arr[k].first;
  k = n - k;
  if (pp + 2 <= n) {
    int z = pp + 2;
    long long sum = 0;
    for (int i = 0; i < pp + 2; ++i) sum += a[i];
    ans = min(ans, sum);
  }
  calc(pp);
  calc(pp + 1);
  printf("%lld\n", ans);
  return 0;
}
