#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; (i * i) <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int nerPr(int n) {
  for (int i = n;; i++) {
    if (isPrime(i)) return i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  int mn = (int)1e9;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    a.push_back(d);
    mn = min(mn, d);
    if (d == 1) {
      cout << "-1\n";
      exit(0);
    }
  }
  cout << 1;
}
