#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
void Main();
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
void Main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (b >= 10) {
      cnt++;
      b /= 10;
    }
    cout << (1ll * cnt * a) << "\n";
  }
}
