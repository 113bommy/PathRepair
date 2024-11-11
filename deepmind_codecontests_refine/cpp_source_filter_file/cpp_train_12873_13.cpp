#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  float k, n, s, p, t, t2;
  cin >> k >> n >> s >> p;
  t = ceil(n / s);
  t *= k;
  t2 = ceil(t / p);
  cout << t2;
  return 0;
}
