#include <bits/stdc++.h>
using namespace std;
int main() {
  int k1, k2, k3;
  int k[1555];
  memset(k, 0, sizeof(k));
  cin >> k1 >> k2 >> k3;
  k[k1]++;
  k[k2]++;
  k[k3]++;
  if (k[1] || k[2] == 2 || k[3] == 3)
    cout << "YES" << endl;
  else if (k[2] == 1 && k[4] == 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
