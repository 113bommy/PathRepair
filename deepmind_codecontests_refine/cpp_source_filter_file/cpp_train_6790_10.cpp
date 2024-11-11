#include <bits/stdc++.h>
using namespace std;
int nodig(int n) { return (int)floor(1 + log10((double)n)); }
int main() {
  long long int te;
  cin >> te;
  while (te--) {
    long long int a, b;
    cin >> a >> b;
    long long int s = nodig(b), c = 0, t = s;
    while (s--) {
      c *= 10;
      c += 9;
    }
    if (b - s == 0)
      cout << a * t << "\n";
    else
      cout << a * t - a << "\n";
  }
}
