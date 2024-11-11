#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long INF64 = 1e18;
const long long INF32 = 1e9;
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0L);
const long double EPS = static_cast<long double>(1e-9);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    for (long long i = (0); i < (n); i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
    }
    sort(a, a + n);
    long long m = (n - 1) / 2;
    long long b[2] = {0, 0};
    vector<long long> res[2];
    for (long long i = (0); i < (m); i++) {
      long long j = n - i - 2;
      b[i % 2] += a[i].first + a[j].first;
      res[i % 2].push_back(a[i].second);
      res[i % 2].push_back(a[j].second);
    }
    if (m % 2) {
      b[1] += a[m].first;
      res[1].push_back(a[m].second);
    }
    if (b[0] < b[1])
      res[0].push_back(a[n - 1].second);
    else
      res[1].push_back(a[n - 1].second);
    for (long long k = (0); k < (2); k++) {
      cout << res[k].size() << endl;
      for (long long &i : res[k]) cout << i << ' ';
      cout << endl;
    }
  }
  return 0;
}
