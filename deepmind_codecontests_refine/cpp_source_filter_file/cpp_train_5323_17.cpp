#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[200];
int main() {
  long long n, x = 0;
  cin >> n;
  while (n > 0) {
    if (n % 7) {
      n -= 4;
      x++;
    } else {
      while (x--) cout << 4;
      for (int i = 0; i < n / 7; i++) cout << 7;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
