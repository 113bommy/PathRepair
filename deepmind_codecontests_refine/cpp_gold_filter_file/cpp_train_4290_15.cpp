#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long s;
struct salary {
  long long l, r;
};
salary a[200001];
bool cmp(salary a, salary b) { return a.l > b.l; }
void nhap() {
  scanf("%d%lld", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].l, &a[i].r);
  }
  sort(a + 1, a + n + 1, cmp);
}
bool check(long long k) {
  int dem = n / 2 + 1;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].l <= k && a[i].r >= k && dem > 0) {
      dem--;
      sum += k;
    } else {
      sum += a[i].l;
      dem -= (a[i].l > k);
    }
  }
  if (dem > 0) {
    return false;
  }
  return sum <= s;
}
void binary() {
  long long l = a[n / 2 + 1].l;
  long long r = s;
  long long kq = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      kq = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << kq;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    nhap();
    binary();
    cout << "\n";
  }
  return 0;
}
