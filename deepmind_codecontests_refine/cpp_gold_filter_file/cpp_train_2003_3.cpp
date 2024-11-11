#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> v;
    v.resize(m);
    for (int j = 0; j < m; j++) cin >> v[j];
    int maxV = 0;
    for (int k = 1; k < m; k++) {
      if (v[k - 1] <= v[k])
        continue;
      else {
        int x = 1;
        while (pow(2, x) - 1 < v[k - 1] - v[k]) x++;
        v[k] = v[k - 1];
        maxV = max(maxV, x);
      }
    }
    cout << maxV << endl;
  }
  return 0;
}
