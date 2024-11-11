#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  float k, n, s, p;
  cin >> k >> n >> s >> p;
  return cout << ceil((ceil(n / s) * k) / p), 0;
}
