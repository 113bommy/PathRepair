#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
struct Node {
  long long x;
  int i;
} a[300001];
bool cmp(const Node &s1, const Node &s2) { return s1.x < s2.x; }
long long s[300001];
int main() {
  long long n, k;
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i].x), a[i].i = i;
  scanf("%I64d", &k);
  sort(a + 1, a + n + 1, cmp);
  for (long long i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].x;
  long long temp = 0;
  for (long long i = 2; i <= k; i++) temp += a[i].x * (i - 1) - s[i - 1];
  long long m2 = temp, m3 = 1;
  for (long long i = k + 1; i <= n; i++) {
    temp += a[i - k].x * (k - 1) - (s[i - 1] - s[i - k]) * 2 + a[i].x * (k - 1);
    if (temp < m2) m2 = temp, m3 = i - k + 1;
  }
  for (long long i = m3; i < m3 + k; i++) printf("%I64d ", a[i].i);
  return 0;
}
