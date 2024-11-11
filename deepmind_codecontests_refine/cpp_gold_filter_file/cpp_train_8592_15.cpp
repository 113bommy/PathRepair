#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  for (int it = 0; it < T; it++) {
    int n, p;
    cin >> n >> p;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      int x;
      cin >> x;
      sum = (sum + x) % n;
    }
    for (int i = 1; i <= n; i++) {
      if (((i + sum) % n) == (p % n)) cout << i << endl;
    }
  }
}
