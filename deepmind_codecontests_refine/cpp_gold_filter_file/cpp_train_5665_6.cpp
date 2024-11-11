#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int oe = 0, eo = 0, oo = 0;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a % 2) {
      if (b % 2)
        oo++;
      else
        oe++;
    } else {
      if (b % 2) eo++;
    }
  }
  int up = (oo + oe) % 2, lo = (oo + eo) % 2;
  if (!up && !lo)
    cout << "0\n";
  else {
    if (up && lo && (oe > 0 || eo > 0))
      cout << "1\n";
    else
      cout << "-1\n";
  }
}
