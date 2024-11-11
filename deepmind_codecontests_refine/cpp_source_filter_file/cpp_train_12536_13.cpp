#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long OO = (long long)10e9 + 1;
const int MAX = 10e4;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, w = 0, countt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!x)
      countt += w;
    else
      w++;
  }
  cout << countt << endl;
}
