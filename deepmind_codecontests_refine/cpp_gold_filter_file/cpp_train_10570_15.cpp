#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
long long n, v[100010], x, y, z;
long long abss(long long a) {
  if (a < 0) a = -a;
  return a;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  sort(v + 1, v + 1 + n);
  for (int i = n; i >= 1; --i) {
    if (x <= y)
      x += v[i];
    else
      y += v[i];
  }
  cout << abss(x - y) + 1;
  return 0;
}
