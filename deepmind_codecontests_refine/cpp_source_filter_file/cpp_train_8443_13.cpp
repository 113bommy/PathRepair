#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, a, b, c, d, ar[100];
  int ansa, ansb, ansc, ansd = 10000, ans;
  vector<int> va, vb, vc, vd;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    va.push_back(a);
    vb.push_back(b);
    vc.push_back(c);
    vd.push_back(d);
    ar[i] = 1;
  }
  for (i = 0; i < va.size(); i++) {
    for (j = i + 1; j < va.size(); j++) {
      if (va[i] < va[j] && vb[i] < vb[j] && vc[i] < vc[j] && ar[j] == 1) {
        ar[i] = 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (ansd > vd[i] && ar[i] == 1) {
      ansd = vd[i];
      ans = i;
    }
  }
  cout << ans << endl;
}
