#include <bits/stdc++.h>
using namespace std;
long long i, n, a, b, c, d;
int main() {
  cin >> n;
  for (i = 0; i < n * 2; i++) cin >> a >> b, c += a, d += b;
  cout << c / n << " " << d / n;
}
