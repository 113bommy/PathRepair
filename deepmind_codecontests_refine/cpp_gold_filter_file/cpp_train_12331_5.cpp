#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, max, l;
  long long m[1001], p[1001];
  int a1, a2, a3, b1, b2, b3, med, puo;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
  cin >> n;
  med = b1 + b2 + b3;
  puo = a1 + a2 + a3;
  if (puo == 0 || med == 0) {
    if (puo == 0 && med != 0)
      if ((med - 1) / 10 + 1 <= n)
        cout << "YES";
      else
        cout << "NO";
    if (puo != 0 && med == 0)
      if ((puo - 1) / 5 + 1 <= n)
        cout << "YES";
      else
        cout << "NO";
    if (puo == 0 && med == 0) cout << "YES";
  } else {
    if ((puo - 1) / 5 + 2 + (med - 1) / 10 <= n)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
