#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000009;
void solve() {
  unsigned long long n, x;
  cin >> n >> x;
  int count = 0;
  for (int i = 1; i <= floor(sqrt(x)); i++) {
    if ((x % i == 0) && (i <= n) && (x / i <= n)) {
      if ((x / i != i)) {
        count += 2;
      } else {
        count++;
      }
    }
  }
  cout << count;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
