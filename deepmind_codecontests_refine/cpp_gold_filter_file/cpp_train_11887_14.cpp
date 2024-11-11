#include <bits/stdc++.h>
using namespace std;
const int oo = 7 + ((int)1e9);
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
vector<long long> v_d;
void getdivisors(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v_d.push_back(i);
      if (n / i != i) v_d.push_back(n / i);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n;
  m = n;
  n = n + n;
  if (((n * (n + 1)) / 2) % 2 == 0) return cout << "NO", 0;
  cout << "YES" << endl;
  cout << 1 << " ";
  long long val = 1;
  for (long long i = 0; i < n - 1; i++) {
    if (i % 2 == 0) {
      val = (val + 3) % n;
      if (val == 0)
        cout << n << " ";
      else
        cout << val << " ";
    } else {
      val = (val + 1) % n;
      if (val == 0)
        cout << n << " ";
      else
        cout << val << " ";
    }
  }
  return 0;
}
