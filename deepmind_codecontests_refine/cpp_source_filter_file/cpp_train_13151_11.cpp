#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a;
  int d;
  cin >> n >> a >> d;
  vector<int> t;
  vector<int> v;
  vector<double> vres;
  for (int i = 0; i < n; i++) {
    int it, iv;
    cin >> it >> iv;
    t.push_back(it);
    v.push_back(iv);
  }
  for (int i = 0; i < n; i++) {
    double vr = 0.0;
    double pt = (double)v[i] / a;
    double ps = (double)v[i] * pt / 2;
    if (ps > (double)d) {
      double pvp = sqrt((double)a * d * 2);
      vr = t[i] + pvp / a;
    } else {
      double pss = d - ps;
      double ptt = pss / v[i];
      vr = t[i] + pt + ptt;
    }
    if (i > 0 && vr < vres[i - 1]) {
      vr = vres[i - 1];
    }
    vres.push_back(vr);
  }
  for (int i = 0; i < n; i++) {
    cout << vres[i];
  }
  return 0;
}
