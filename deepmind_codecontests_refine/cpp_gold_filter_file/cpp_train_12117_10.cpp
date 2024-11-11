#include <bits/stdc++.h>
using namespace std;
map<int, int> sg;
map<int, bool> us;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, d;
    cin >> x >> d;
    sg[x] = x + d;
    us[x] = true;
    if (us[x + d] && sg[x + d] == x && sg[x] == x + d) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO";
}
