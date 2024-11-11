#include <bits/stdc++.h>
using namespace std;
string a;
int Deal(string p) {
  if (p == "UL" || p == "DR") return 1;
  if (p == "UR" || p == "DL") return 2;
  return 3;
}
long long ans(1);
int n;
int main() {
  cin >> n;
  long long tA = 0, tB = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("\n");
    cin >> a;
    int t = Deal(a);
    if (t == 1) {
      ans = ans + ans - 2 * (tA * tB) - tA;
      ++tA;
    }
    if (t == 2) {
      ans = ans + ans - 2 * (tA * tB) - tB;
      ++tB;
    }
    if (t == 3) {
      ans <<= 2;
      ans -= (tA * tB) * 3 + 2 * tA + 2 * tB;
      ++tA;
      ++tB;
    }
  }
  cout << ans << endl;
}
