#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  int n, t;
  cin >> n >> t;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    int y = 86400 - x;
    t -= y;
    if (t <= 0) return cout << i, 0;
  }
}
