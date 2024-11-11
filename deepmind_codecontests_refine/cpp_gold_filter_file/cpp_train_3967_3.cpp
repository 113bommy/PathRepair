#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, m, k = 200, y = 200;
  cin >> n >> m;
  cout << string(k, '9');
  cout << (string(k - 1, '0') + "1") << endl;
  cout << string(y, '9') << endl;
}
