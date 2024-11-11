#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream inf("input.txt");
  string s[100];
  int n, j = -1, j1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int hs, hu, a, b, c, d, e;
    cin >> s[i] >> hs >> hu >> a >> b >> c >> d >> e;
    if (hs * 100 - hu * 50 + a + b + c + d + e > j) {
      j = hs * 100 - hu * 50 + a + b + c + d + e;
      j1 = i;
    }
  }
  cout << s[j1];
}
