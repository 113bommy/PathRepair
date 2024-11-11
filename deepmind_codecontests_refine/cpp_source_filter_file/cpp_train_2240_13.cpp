#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long n, a[N], f[N], ans, f1[N], f2[N];
void add(long long x, long long c) {
  for (; x < N; x += (x & -x)) f[x] += c;
}
long long get(long long x) {
  long long cnt = 0;
  for (; 0 < x; x -= (x & -x)) cnt += f[x];
  return cnt;
}
void compress() {
  vector<long long> u;
  for (int i = 0; i < n; i++) u.push_back(a[i]);
  sort(u.begin(), u.end());
  u.resize(unique(u.begin(), u.end()) - u.begin());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  compress();
  for (int i = 0; i < n; i++) a[i]++;
  for (int i = 0; i < n; i++) {
    add(a[i], 1);
    f1[i] = i - get(a[i]) + 1;
  }
  for (int i = 0; i < n; i++) {
    add(a[i], -1);
  }
  for (int i = n - 1; i >= 0; i--) {
    add(a[i], 1);
    f2[i] = get(a[i] - 1);
  }
  for (int i = 0; i < n; i++) {
    ans += f1[i] * f2[i];
  }
  cout << ans;
}
