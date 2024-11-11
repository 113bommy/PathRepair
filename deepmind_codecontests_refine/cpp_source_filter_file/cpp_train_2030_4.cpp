#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> H;
int s[1099];
int ss;
int main() {
  ios ::sync_with_stdio(false);
  int n;
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x;
    ss = 0;
    cin >> x;
    if (x == 0) {
      cout << "YES\n";
      exit(0);
    }
    for (auto xx : H)
      if ((x + xx.first) % m == 0) {
        cout << "YES\n";
        exit(0);
      } else
        s[++ss] = (x + xx.first) % m;
    H[x] = 1;
    for (int ii = 1; ii <= ss; ++ii) H[s[ii]] = 1;
  }
  cout << "NO\n";
  return 0;
}
