#include <bits/stdc++.h>
using namespace std;
double pw(double p, long long int t) {
  if (!t) {
    return 1;
  }
  if (t == 1) {
    return p;
  }
  if (t % 2) {
    return p * pw(p * p, (t - 1) / 2);
  }
  return p * pw(p * p, t / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, t;
  cin >> n >> t;
  cout << setprecision(9) << fixed << n * pw(1.000000011, t) << endl;
  return 0;
}
