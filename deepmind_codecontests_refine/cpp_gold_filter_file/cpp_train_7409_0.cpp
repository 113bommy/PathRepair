#include <bits/stdc++.h>
using namespace std;
ifstream Cin("input.txt");
ofstream Cout("output.txt");
int main() {
  long long n, d, i, a, b, ans = 0;
  cin >> n >> d;
  cin >> b;
  for (i = 1; i < n; i++) {
    cin >> a;
    if (b >= a) ans += (b - a) / d + 1, a += ((b - a) / d + 1) * d;
    b = a;
  }
  cout << ans;
}
