#include <bits/stdc++.h>
const long long mod = 1000000007;
const double PI = 3.14159265358979323846;
using namespace std;
long long compute(long long cnt, vector<long long> f1, vector<long long> f2,
                  vector<long long> f3) {
  long long minR = INT_MAX;
  for (long long i = 0; i < 26; i++) f1[i] -= cnt * f2[i];
  for (long long i = 0; i < 26; i++) {
    if (f3[i] >= 1) {
      minR = min(minR, f1[i] / f3[i]);
    }
  }
  return minR;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for (long long i = 0; i < n; i++) cin >> x[i];
    for (long long i = 0; i < n; i++) {
      cout << (((x[i] % b) * (a % b)) % b) << " ";
    }
  }
}
