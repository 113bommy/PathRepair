#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
int n, c, tkm, p[100], t[100], a, b, i;
int main() {
  cin >> n >> c;
  for (i = 1; i <= n; i++) cin >> p[i];
  for (i = 1; i <= n; i++) cin >> t[i];
  for (i = 1; i <= n; i++) {
    tkm += t[i];
    a += max(0, p[i] - c * tkm);
  }
  tkm = 0;
  for (i = n; i >= 1; i--) {
    tkm += t[i];
    b += max(0, p[i] - c * tkm);
  }
  if (a == b)
    cout << "Tie";
  else if (a > b)
    cout << "Limak";
  else
    cout << "Radewoosh";
  return 0;
}
