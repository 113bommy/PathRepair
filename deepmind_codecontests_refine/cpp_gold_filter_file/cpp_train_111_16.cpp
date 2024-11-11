#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 7;
const double pi =
    3.14159265358979323846264338327950288419716939937510582097494459;
const int N = 5e5 + 5;
const int oo = 1e9 + 7;
const long long OO = 1e18;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> vec(n);
  int sum = 0, maxi = 0;
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    maxi = max(maxi, vec[i]);
    sum += vec[i];
  }
  for (int k = maxi; k <= 201; k++) {
    int s = 0;
    for (int i = 0; i < n; i++) s += (k - vec[i]);
    if (s > sum) {
      cout << k << endl;
      return 0;
    }
  }
}
