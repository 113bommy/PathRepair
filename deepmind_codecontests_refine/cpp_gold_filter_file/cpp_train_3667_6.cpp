#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 11;
const long long inf = 1e9 + 7;
const long long MOD = 1e9 + 7;
const long long C = 200;
const long double EPS = 1e-9;
long long cnt[35];
long long lst[35];
bool check(vector<long double> v) {
  for (long long i = 1; i < v.size(); i++) {
    if (v[i] > v[i - 1]) return 1;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long double> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  long long f = 65;
  while (f--) {
    for (long long i = 0; i < n; i++) {
      long long j = i + 1;
      for (j = i + 1; j < n; j++) {
        if (v[j] - v[j - 1] > EPS) {
          j--;
          break;
        }
      }
      j = min(j, n - 1);
      long double sum = 0;
      for (long long k = i; k <= j; k++) {
        sum += v[k];
      }
      sum /= (long double)(j - i + 1);
      for (long long k = i; k <= j; k++) {
        v[k] = sum;
      }
      i = j;
    }
  }
  for (auto it : v) {
    cout << fixed << setprecision(10) << it << '\n';
  }
  return 0;
}
