#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  if ((n - 1) + (y - n + 1) * (y - n + 1) < x or y < n)
    cout << -1;
  else {
    for (int i = 1; i < n; i++) cout << "1\n";
    cout << y - n + 1;
  }
}
