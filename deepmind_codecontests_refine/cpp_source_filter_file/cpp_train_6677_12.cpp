#include <bits/stdc++.h>
using namespace std;
void mysol() {
  int64_t a, b, c;
  cin >> a >> b >> c;
  int64_t extra = a & 1;
  a -= (a & 1);
  if (b <= c / 2)
    cout << (a + extra) * b;
  else
    cout << (a / 2) * c + b;
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  cin >> T;
  while (T--) mysol();
  return 0;
}
