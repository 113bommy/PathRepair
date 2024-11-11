#include <bits/stdc++.h>
using namespace std;
long long a[5], ans = 1ll << 60, rs;
int g;
vector<long long> v;
bool use[5];
char p[4];
int main() {
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  cin >> p[0] >> p[1] >> p[2];
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 4; j++) {
      use[i] = use[j] = 1;
      v.clear();
      if (p[0] == '*')
        v.push_back(a[i] * a[j]);
      else
        v.push_back(a[i] + a[j]);
      if (!use[0]) v.push_back(a[0]);
      if (!use[1]) v.push_back(a[1]);
      if (!use[2]) v.push_back(a[2]);
      if (!use[3]) v.push_back(a[3]);
      for (int t = 0; t < 2; t++)
        for (int k = t + 1; k < 3; k++) {
          if (t != 0 && k != 0) g = 0;
          if (t != 1 && k != 1) g = 1;
          if (t != 2 && k != 2) g = 2;
          if (p[1] == '*') {
            if (p[2] == '*')
              rs = v[t] * v[k] * v[g];
            else
              rs = v[t] * v[k] + v[g];
          } else {
            if (p[2] == '*')
              rs = (v[t] + v[k]) * v[g];
            else
              rs = v[t] + v[k] + v[g];
          }
          ans = min(ans, rs);
        }
      use[0] = use[1] = use[2] = use[3] = 0;
    }
  cout << ans;
  return 0;
}
