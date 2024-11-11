#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, r = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x, g, b;
    cin >> x >> g >> b;
    if (g >= b || g >= x) {
      cout << x << endl;
    } else {
      long long t = (x + 1) / 2 - g;
      long long a = (t + (g - (t % g)) % g) / g;
      if (a * b + a * g + g >= x) {
        cout << t + a * b + g << endl;
      } else {
        cout << x << endl;
      }
    }
  }
}
