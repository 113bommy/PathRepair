#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  if (n > y) {
    cout << -1;
    return 0;
  }
  if ((y - n + (long long)1) * (y - n + (long long)1) + n - (long long)1 >= x) {
    for (int i = 0; i < n - 1; i++) cout << 1 << endl;
    cout << y - n + (long long)1;
  } else
    cout << -1;
  return 0;
}
