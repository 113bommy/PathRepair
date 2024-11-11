#include <bits/stdc++.h>
using namespace std;
const long long prb = 100;
const long long N = 100005;
const long long NN = 105;
const long long HASH1 = 2250119;
const long long HASH2 = 2452343;
const double pi = 3.14159;
const long long MAX = 2e5 + 123;
const long long MOD = 1e9 + 7;
const long long INF = 1000000000000000000;
const long long pw = 31;
void speed() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n, m, a[505][505], line[505], column[505];
vector<long long> v;
void hajime() {
  cin >> n >> m;
  for (long long i = 2; i <= 100000; i++) {
    bool ok = 1;
    for (long long j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) ok = 0;
    }
    if (ok) v.push_back(i);
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
      long long l = 0, r = v.size() - 1;
      while (l < r) {
        long long md = (l + r) / 2;
        if (v[md] >= a[i][j])
          r = md;
        else
          l = md + 1;
      }
      line[j] += abs(v[r] - a[i][j]);
      column[i] += abs(v[r] - a[i][j]);
    }
  }
  long long mn = INF;
  for (long long i = 1; i <= n; i++) mn = min(mn, column[i]);
  for (long long j = 1; j <= m; j++) mn = min(mn, line[j]);
  cout << mn;
}
int main() {
  long long miyagi = 1;
  speed();
  for (long long i = 1; i <= miyagi; i++) {
    hajime();
  }
}
