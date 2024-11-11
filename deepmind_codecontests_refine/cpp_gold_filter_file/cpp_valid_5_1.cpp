#include <bits/stdc++.h>
using namespace std;
void TombStonePiledrider(void) {
  long long int a;
  cin >> a;
  string c;
  cin >> c;
  string b;
  cin >> b;
  long long int d = 0;
  for (long long int i = 0; i < a; ++i) {
    if (b[i] == '0') {
      continue;
    }
    bool ok = (c[i] == '0');
    if (!ok && i - 1 >= 0) {
      ok = (c[i - 1] == '1');
      if (ok) {
        c[i - 1] = 'k';
      }
    }
    if (!ok && i + 1 < a) {
      ok = (c[i + 1] == '1');
      if (ok) {
        c[i + 1] = 'k';
      }
    }
    d += ok;
  }
  cout << d << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  long long int TotalTestCase = 1;
  std::cin >> TotalTestCase;
  while (TotalTestCase--) {
    TombStonePiledrider();
  }
  return 0;
}
