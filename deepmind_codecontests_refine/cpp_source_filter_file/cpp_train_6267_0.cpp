#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-5);
long long isGreater(long double x, long double y) {
  if (abs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
long long n;
bool valid(long long i) { return i >= 0 && i < n; }
long long getSum(const vector<long long> &cum, long long l, long long r) {
  long long ret = 0;
  if (valid(r)) ret += cum[r];
  if (valid(l - 1)) ret -= cum[l - 1];
  return ret;
}
long long bestAns;
long long solve(vector<long long> a, long long d) {
  long long sum = 0;
  for (long long i = 0; i < (long long)(a).size(); ++i) {
    a[i] = a[i] % d;
    sum += a[i];
    sum %= d;
  }
  if (sum != 0) return LLONG_MAX;
  sum = 0;
  long long size = 0;
  long long ans = 0;
  for (long long i = 0; i < (long long)(a).size(); ++i) {
    sum += a[i];
    size++;
    if (sum >= d) {
      long long extra = sum - d;
      a[i] -= extra;
      long long st = i - size + 1, en = i;
      long long minSum = LLONG_MAX, temp = 0, inc = 0, dec = sum;
      for (long long j = st; j <= en; ++j) temp += 1LL * a[j] * (j - st + 1);
      for (long long mid = st; mid <= en; ++mid) {
        temp += inc;
        temp -= dec;
        dec -= a[mid];
        inc += a[mid];
        minSum = min(minSum, temp);
      }
      ans += minSum;
      if (ans > bestAns) break;
      a[i] = extra;
      size = 0;
      sum = 0;
      --i;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == 1) {
    cout << -1;
    return 0;
  }
  bestAns = solve(a, sum);
  for (long long i = 2; i <= sum / i; ++i) {
    if (sum % i == 0) {
      bestAns = min(bestAns, solve(a, i));
      while (sum % i == 0) {
        sum /= i;
      }
    }
  }
  if (sum > 1) bestAns = min(bestAns, solve(a, sum));
  cout << bestAns;
  return 0;
}
