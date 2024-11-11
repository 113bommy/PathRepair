#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, a{0}, b{0}, eo{0}, oe{0}, oo{0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a % 2 == 0 & b % 2 != 0) eo++;
    if (a % 2 != 0 & b % 2 == 0) oe++;
    if (a % 2 != 0 & b % 2 != 0) oo++;
  }
  if ((oe + oo) % 2 != 0 && (oo + eo) % 2 != 0 && n != 1)
    cout << "1"
         << "\n";
  else if ((oe + oo) % 2 == 0 && (oo + eo) % 2 == 0)
    cout << "0"
         << "\n";
  else
    cout << "-1"
         << "\n";
}
