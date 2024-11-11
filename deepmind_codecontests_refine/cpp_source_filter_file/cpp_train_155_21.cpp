#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (n < 5 || n + 3 > k) {
    return cout << "-1\n", 0;
  }
  vi restric(n + 1, 0);
  for (int x : {a, b, c, d}) {
    restric[x] = 1;
  }
  cout << a << " " << c;
  for (int i = 1; i <= n; i++) {
    if (!restric[i]) {
      cout << " " << i;
    }
  }
  cout << " " << d << " " << b;
  cout << '\n';
  cout << c << " " << a;
  for (int i = 1; i <= n; i++) {
    if (!restric[i]) {
      cout << " " << i;
    }
  }
  cout << " " << b << " " << d;
  cout << '\n';
  return 0;
}
