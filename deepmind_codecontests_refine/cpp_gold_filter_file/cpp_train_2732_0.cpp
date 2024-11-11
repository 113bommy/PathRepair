#include <bits/stdc++.h>
using namespace std;
const long long NN = 800;
const int N = 5e3 + 7;
const int M = 22;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
const double long rf = 1e-14;
const int B = sqrt(N);
vector<long long> p;
bool ok(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve1() {
  vector<long long> v;
  int aks = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    int j = i;
    long long cnt = 1;
    while (j < (int)p.size()) {
      if (cnt > 1e18 / p[j] || cnt * p[j] > 1e18) break;
      cnt *= p[j];
      j += 1;
    }
    i = j - 1;
    aks += 1;
    cout << "? " << cnt << endl;
    long long x;
    cin >> x;
    for (auto y : p) {
      if (x % y == 0) v.push_back(y);
    }
  }
  long long ans = 1;
  for (int i = 0; i < (int)v.size(); i++) {
    if (aks == 22) {
      for (int j = 0; j < (int)v.size() - i; j++) ans *= 2;
      break;
    }
    aks += 1;
    long long cnt = 1;
    while (cnt <= 1e9 / v[i] && cnt * v[i] <= 1e9) {
      cnt *= v[i];
    }
    i += 1;
    long long x;
    if (i == (int)v.size()) {
      cout << "? " << cnt << endl;
      cin >> x;
    } else {
      while (cnt <= 1e18 / v[i] && cnt * v[i] <= 1e18) {
        cnt *= v[i];
      }
      cout << "? " << cnt << endl;
      cin >> x;
    }
    for (long long j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        long long k = 0;
        while (x % j == 0) {
          x /= j;
          k += 1;
        }
        ans *= (k + 1);
      }
    }
    if (x > 1) ans *= 2;
  }
  cout << "! " << max(7ll, ans) + ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= NN; i++) {
    if (ok(i)) p.push_back(i);
  }
  int cghf = 1;
  cin >> cghf;
  while (cghf--) {
    solve1();
  }
}
