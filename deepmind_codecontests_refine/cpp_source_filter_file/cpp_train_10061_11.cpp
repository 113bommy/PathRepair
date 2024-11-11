#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U>
using umap = unordered_map<T, U>;
template <typename T>
using uset = unordered_set<T>;
set<int> primes;
void genPrimes(int B) {
  vector<bool> a(B + 1, true);
  for (int i = 2; i * i <= B; i++) {
    if (a[i]) {
      for (int j = i * i; j <= B; j += i) {
        a[j] = false;
      }
    }
  }
  for (int i = 2; i <= B; i++) {
    if (a[i]) primes.insert(i);
  }
}
int getP(int n) {
  int mx = 2;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (primes.find(i) != primes.end()) {
        mx = max(mx, i);
      } else if (primes.find(n / i) != primes.end()) {
        mx = max(mx, n / i);
      }
    }
  }
  return mx;
}
int main() {
  ios::sync_with_stdio(false);
  int x2;
  cin >> x2;
  genPrimes(x2);
  int p1 = getP(x2);
  int mn = 1e6;
  for (int x1 = x2 - p1 + 1; x1 <= x2; x1++) {
    int p0 = getP(x1);
    int v = x1 - p0 + 1;
    if (v < 3) continue;
    mn = min(mn, v);
  }
  cout << mn << endl;
  return 0;
}
