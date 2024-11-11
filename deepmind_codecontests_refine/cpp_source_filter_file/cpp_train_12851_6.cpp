#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, maxtime = 1, maxtimen = 0;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    b = max((a / m) + (a % m ? 0 : 1), 1);
    if (b >= maxtime) {
      maxtime = b;
      maxtimen = i;
    }
  }
  cout << (maxtimen + 1) << endl;
  return 0;
}
