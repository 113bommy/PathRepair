#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], k, x, f;
void solve() {
  for (int i = 0; i < n; i++) {
    k += (a[i] + f - 1) / (x + f);
  }
  cout << k * f;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x >> f;
  solve();
}
