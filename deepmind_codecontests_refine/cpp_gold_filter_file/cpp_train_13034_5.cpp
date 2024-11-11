#include <bits/stdc++.h>
using namespace std;
bool isV(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
void tc() {
  int n, m, x;
  cin >> n;
  signed long long int s = 0;
  signed long long int xr = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s += x;
    xr ^= x;
  }
  if (s == 2 * xr) {
    cout << 0 << "\n";
    return;
  }
  signed long long int a, b, c;
  a = xr;
  b = 0;
  c = s + xr;
  cout << 3 << "\n";
  cout << a << " " << b << " "
       << " " << c << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  unsigned long long int q;
  cin >> q;
  while (q--) tc();
  return 0;
}
