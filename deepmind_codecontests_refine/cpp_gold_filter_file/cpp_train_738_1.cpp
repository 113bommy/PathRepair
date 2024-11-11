#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
double EPSILON = numeric_limits<double>::epsilon();
bool AreSame(double a, double b) { return fabs(a - b) < EPSILON; }
long long primeFactors(long long n) {
  long long cnt = LLONG_MAX;
  if (n % 2 == 0) return 2;
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      cnt = min(cnt, i);
      n = n / i;
    }
  }
  if (n > 2) cnt = min(cnt, n);
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long n;
  cin >> n;
  long long cnt = primeFactors(n);
  if (n - cnt == 0)
    cout << 1;
  else if (cnt == 2)
    cout << n / 2;
  else
    cout << (n - cnt) / 2 + 1;
  return 0;
}
