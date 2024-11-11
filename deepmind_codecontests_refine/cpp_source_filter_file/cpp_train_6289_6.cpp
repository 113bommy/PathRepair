#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long b[100000 + 1], p[100000 + 1];
long long n, m, a;
bool check(int k) {
  int ans = a;
  for (int i = n - k; i < n; ++i) {
    ans -= max(p[i - n + k] - b[i], (long long)0);
  }
  if (ans < 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> a;
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) cin >> p[i];
  sort(b, b + n);
  sort(p, p + m);
  int beg = 0;
  int last = min(n, m) + 1;
  int mid = (beg + last) / 2;
  while (last - beg > 1) {
    mid = (beg + last) / 2;
    if (check(mid)) {
      beg = mid;
    } else
      last = mid;
  }
  long long ans2 = 0;
  for (int i = 0; i < beg; ++i) {
    ans2 += p[i];
  }
  cout << beg << " " << max(ans2 - a, (long long)0);
}
