#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn], b[maxn];
long long sum1[maxn], sum2[maxn];
vector<int> c1, c2;
long long n, d, m;
int len1, len2;
int cmp(int x, int y) { return x > y; }
bool check(long long pos, long long num) {
  if ((pos + len2 - num) >= 1ll * (num - 1) * d) return true;
  return false;
}
int Bin(int pos) {
  pos = len1 - pos;
  int l = 0, r = len2;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(pos, mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
int main() {
  scanf("%lld%lld%lld", &n, &d, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] <= m)
      c1.push_back(a[i]);
    else
      c2.push_back(a[i]);
  }
  sort(c1.begin(), c1.end(), cmp);
  sort(c2.begin(), c2.end(), cmp);
  for (int i = 1; i <= c1.size(); i++) {
    sum1[i] = sum1[i - 1] + c1[i - 1];
  }
  for (int i = 1; i <= c2.size(); i++) {
    sum2[i] = sum2[i - 1] + c2[i - 1];
  }
  long long ans = 0;
  len1 = c1.size(), len2 = c2.size();
  for (int i = 0; i <= len2; i++) {
    if (len1 + len2 - i < 1ll * (i - 1) * d) continue;
    long long tmp = 0;
    long long res = min(1ll * len1, 1ll * len2 - i + len1 - 1ll * (i - 1) * d);
    tmp += sum1[res];
    tmp += sum2[i];
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
