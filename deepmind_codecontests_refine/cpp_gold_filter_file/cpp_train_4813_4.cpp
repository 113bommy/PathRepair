#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, id, ans = 0x3f3f3f3f, ansa, ansb, ansc;
    cin >> a >> b >> c;
    for (int i = 1; i <= c; i++)
      for (int x = 1; x * i <= 20000; x++)
        for (int y = x; y * i <= 20000; y += x)
          if (abs(a - i) + abs(b - x * i) + abs(c - y * i) < ans)
            ans = abs(a - i) + abs(b - x * i) + abs(c - y * i), ansa = i,
            ansb = x * i, ansc = y * i;
    cout << ans << "\n" << ansa << " " << ansb << " " << ansc << "\n";
  }
}
