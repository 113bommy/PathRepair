#include <bits/stdc++.h>
using namespace std;
int main() {
  int in[1010] = {0};
  int out[1010] = {0};
  int c[1010] = {0}, a, b, d, n, p, i;
  cin >> n >> p;
  for (i = 0; i < p; i++) {
    cin >> a >> b >> d;
    out[a] = b;
    in[b] = a;
    c[a] = d;
  }
  vector<vector<int> > vx;
  int j = 0;
  for (i = 0; i < n; i++) {
    int k = i;
    int p = 1e9;
    if (in[k] == 0 && out[k] != 0) {
      vector<int> v;
      vx.push_back(v);
      vx[j].push_back(k);
      while (out[k] != 0) {
        p = min(c[k], p);
        k = out[k];
      }
      vx[j].push_back(k);
      vx[j++].push_back(p);
    }
  }
  sort(vx.begin(), vx.end());
  cout << vx.size() << endl;
  for (i = 0; i < vx.size(); i++) {
    cout << vx[i][0] << " " << vx[i][1] << " " << vx[i][2] << endl;
  }
  return 0;
}
