#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, x, y;
    cin >> a >> b >> x >> y;
    x++;
    y++;
    long long int d = x - 1;
    long long int e = y - 1;
    long long int f = a - x;
    long long int g = b - y;
    long long int h = d * b;
    long long int i = b * f;
    long long int j = a * e;
    long long int k = a * g;
    cout << max(max(max(h, i), j), k) << endl;
  }
}
