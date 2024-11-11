#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  ll n, k;
  cin >> n >> k;
  int mn = 2e9;
  for (int i = 1; i < sqrt(n) + 1; i++) {
    if (n % i == 0) {
      int y = i * k;
      int x = n / i * k;
      for (int j = 0; y / k == i; j++) {
        if ((y % k) * (y / k) == n) {
          mn = min(mn, y);
          break;
        }
        y++;
      }
      for (int j = 0; x / k == n / i; j++) {
        if ((x % k) * (x / k) == n) {
          mn = min(mn, x);
          break;
        }
        x++;
      }
    }
  }
  cout << mn << endl;
}
int main() { solve(); }
