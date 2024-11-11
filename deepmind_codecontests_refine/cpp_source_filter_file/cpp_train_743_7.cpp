#include <bits/stdc++.h>
using namespace std;
struct Interval {
  int start, end;
};
bool compare(Interval i1, Interval i2) { return (i1.start < i2.start); }
vector<long long int> factors;
void Divisors(long long int n) {
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        factors.push_back(i);
      else {
        factors.push_back(i);
        factors.push_back(n / i);
      }
    }
  }
}
long long int coun[100005] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, m, t;
  cin >> n >> k >> m >> t;
  while (t--) {
    long long int task, in;
    cin >> task >> in;
    if (task == 0) {
      if (in < k) {
        k = k - in;
        n = n - in;
      } else {
        n = in;
      }
      cout << n << " " << k << endl;
    } else {
      if (in <= k) {
        k = k + 1;
        n = n + 1;
      } else {
        k = k;
        n = k + 1;
      }
      cout << n << " " << k << endl;
    }
  }
  return 0;
}
