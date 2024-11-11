#include <bits/stdc++.h>
using namespace std;
long long a[1011][1011], n, m, sum, s, r, c, x, q, s1, s2, s3, s4, s5, sum1,
    sum2, sum3, sum4, p, sum6, j;
map<long long, long long> fix;
pair<long long, pair<long long, long long> > p1[1000011];
long long go(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b /= 2;
  }
  return res % p;
}
int main() {
  ios::sync_with_stdio(0);
  p = 998244353;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int w = 1; w <= m; w++) {
      cin >> a[i][w];
      x++;
      p1[x].first = a[i][w];
      p1[x].second.first = i;
      p1[x].second.second = w;
    }
  sort(p1 + 1, p1 + x + 1);
  cin >> r >> c;
  for (int i = 1; i <= x; i++)
    if (p1[i].second.first == r && p1[i].second.second == c) {
      sum = p1[i].first;
      s = i;
      break;
    }
  for (int i = 1; i <= x; i++)
    if (p1[i].first == sum) {
      q = i;
      break;
    }
  swap(p1[q], p1[s]);
  sum = 0;
  s = 0;
  q = 0;
  for (int i = x; i >= 1; i--) fix[p1[i].first] = i;
  p1[0].first = -1;
  for (int i = 1; i <= x; i++) {
    if (p1[i].first == p1[i - 1].first) {
      j = fix[p1[i].first] - 1;
      s = ((((s % p + sum % p) % p +
             (((p1[i].second.first % p) % p) * ((p1[i].second.first % p) % p) *
              (j % p) % p) %
                 p) +
            sum1 % p) +
           ((-2 * p1[i].second.first) % p * (sum2 % p) % p)) %
          p;
      s = (((s % p + (((p1[i].second.second % p) % p) *
                      ((p1[i].second.second % p) % p) * (j % p) % p) %
                         p) +
            sum3 % p) +
           ((-2 * p1[i].second.second) % p * (sum4 % p) % p)) %
          p;
      s = ((go(j, p - 2) % p * (s % p))) % p;
      sum6 = (sum6 + s) % p;
      s1 = (s1 + p1[i].second.first % p) % p;
      s2 = (s2 + ((p1[i].second.first) % p * (p1[i].second.first) % p) % p) % p;
      s3 = (s3 + ((p1[i].second.second) % p * (p1[i].second.second) % p) % p) %
           p;
      s4 = (s4 + p1[i].second.second % p) % p;
      s = 0;
    } else {
      sum = (sum6 % p + sum % p) % p;
      sum1 = (sum1 % p + s2 % p) % p;
      sum2 = (sum2 % p + s1 % p) % p;
      sum3 = (sum3 % p + s3 % p) % p;
      sum4 = (sum4 % p + s4 % p) % p;
      s = 0;
      s1 = 0;
      s2 = 0;
      s3 = 0;
      s4 = 0;
      s5 = 0;
      sum6 = 0;
      j = fix[p1[i].first] - 1;
      s = ((((s % p) % p +
             (((p1[i].second.first % p) % p * (p1[i].second.first % p) % p) *
              (j % p) % p) %
                 p) +
            sum1 % p) +
           ((-2 * p1[i].second.first) % p * (sum2 % p) % p)) %
          p;
      s = (((s % p +
             (((p1[i].second.second % p) * (p1[i].second.second % p) % p) *
              (j % p) % p) %
                 p) +
            sum3 % p) +
           ((-2 * p1[i].second.second) % p * (sum4 % p) % p)) %
          p;
      s = (sum + s) % p;
      s = ((go((j), p - 2) % p * (s % p))) % p;
      if (p1[i].first == p1[i + 1].first) {
        sum6 = (sum6 + s) % p;
        s1 = (s1 + p1[i].second.first % p) % p;
        s2 = (s2 + ((p1[i].second.first) % p * (p1[i].second.first) % p) % p) %
             p;
        s3 =
            (s3 + ((p1[i].second.second) % p * (p1[i].second.second) % p) % p) %
            p;
        s4 = (s4 + p1[i].second.second % p) % p;
      } else {
        sum = (sum % p + s % p) % p;
        sum1 = (sum1 % p +
                (p1[i].second.first % p) * (p1[i].second.first % p) % p) %
               p;
        sum3 = (sum3 % p +
                (p1[i].second.second % p) * (p1[i].second.second % p) % p) %
               p;
        sum2 = (sum2 % p + p1[i].second.first % p) % p;
        sum4 = (sum4 % p + p1[i].second.second % p) % p;
      }
    }
    if (p1[i].first >= a[r][c]) {
      cout << s << endl;
      break;
    }
    s = 0;
  }
}
