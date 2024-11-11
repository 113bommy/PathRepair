#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b >> c;
  if (c == 0) return cout << (b == a ? "YES\n" : "NO\n"), 0;
  cout << ((b - a) % c == 0 && (b - a) / c >= 0 ? "YES\n" : "NO\n");
}
