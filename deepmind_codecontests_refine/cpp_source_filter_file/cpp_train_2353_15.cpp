#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, k, q;
  cin >> n >> k >> q;
  vector<long long> vc(200005, 0);
  while (n--) {
    cin >> x >> y;
    vc[x]++;
    vc[y + 1]--;
  }
  for (int i = 1; i < vc.size(); i++) vc[i] += vc[i - 1];
  for (int i = 0; i < vc.size(); i++) vc[i] = (vc[i] >= 2);
  for (int i = 1; i < vc.size(); i++) vc[i] += vc[i - 1];
  while (q--) {
    cin >> x >> y;
    cout << vc[y] - vc[x - 1] << endl;
  }
  return 0;
}
