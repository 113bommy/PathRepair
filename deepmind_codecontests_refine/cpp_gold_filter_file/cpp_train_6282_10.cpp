#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (abs(b) < abs(a)) return gcd(b, a);
  if (abs(b) % abs(a) == 0)
    return a;
  else
    return gcd(abs(a), abs(b) % abs(a));
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v1(n + 1), v2(m + 1);
  for (int i = 0; i <= n; i++) cin >> v1[i];
  for (int i = 0; i <= m; i++) cin >> v2[i];
  if (n > m) {
    if (v1[0] * v2[0] < 0) {
      cout << "-";
    }
    cout << "Infinity";
  } else if (n == m) {
    int g = gcd(v1[0], v2[0]);
    v1[0] /= g;
    v2[0] /= g;
    if (v2[0] < 0) {
      v2[0] *= -1;
      v1[0] *= -1;
    }
    cout << v1[0] << "/" << v2[0];
  } else
    cout << "0/1";
  return 0;
}
