#include <bits/stdc++.h>
using namespace std;
long long n, k, b, c, a[222222], ans = 1000000000000000000LL, s1, s2, x;
vector<long long> v[5];
int it[5];
void upd(int r, long long a, long long k) {
  long long g = a % 5;
  long long privet1;
  if (g > r)
    privet1 = a + 5 - g + r;
  else
    privet1 = a - g + r;
  s1 += (r + 5 - g) % 5;
  s2 += k * ((privet1 - x) / 5);
  v[g].push_back(a);
  x = privet1;
}
int main() {
  cin >> n >> k >> b >> c;
  for (int i = 0; i < n; i++) {
    int g;
    scanf("%d", &g);
    a[i] = 11111111111LL + g;
  }
  sort(a, a + n);
  if (b >= c * 5) {
    long long s = 0;
    for (int i = 1; i < k; i++) s += a[i] - a[0];
    ans = s * c;
    for (int i = k; i < n; i++) {
      s = s + (a[i] - a[i - 1]) * k - a[i - k] + a[i];
      ans = min(ans, s * c);
    }
    cout << ans;
    return 0;
  }
  for (int r = 0; r < 5; r++) {
    s1 = 0;
    s2 = 0;
    for (int i = 0; i < 5; i++) {
      it[i] = 0;
      v[i].clear();
    }
    for (int i = 0; i < k; i++) {
      upd(r, a[i], i);
    }
    ans = min(ans, s2 * b + s1 * c);
    for (int i = k; i < n; i++) {
      upd(r, a[i], k);
      long long s3, j = 0;
      while (v[j].size() == it[j]) j++;
      s3 = (x - v[j][it[j]]) / 5 * b + (r + 5 - j) % 5 * c;
      for (int q = j + 1; q < 5; q++) {
        if (it[q] == v[q].size()) continue;
        if (s3 < (x - v[q][it[q]]) / 5 * b + ((r + 5 - q) % 5) * c) {
          s3 = (x - v[q][it[q]]) / 5 * b + ((r + 5 - q) % 5) * c;
          j = q;
        }
      }
      s2 -= (x - v[j][it[j]]) / 5;
      s1 -= (r + 5 - j) % 5;
      ans = min(ans, s2 * b + s1 * c);
      it[j]++;
    }
  }
  cout << ans;
}
