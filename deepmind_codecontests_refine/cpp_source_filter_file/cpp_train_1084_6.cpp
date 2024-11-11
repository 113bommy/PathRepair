#include <bits/stdc++.h>
using namespace std;
bool collapses(const vector<vector<float> >& v) {
  float totMass = 0;
  float cog[2];
  cog[0] = 0;
  cog[1] = 0;
  int vs = v.size();
  for (int i = 0; i < vs; i++) {
    float center[] = {(v[i][0] + v[i][2]) / 2, (v[i][1] + v[i][3]) / 2};
    float mass = v[i][0] - v[i][2];
    mass = mass * mass * mass;
    mass *= (mass >= 0 ? 1 : -1);
    cog[0] = mass * center[0] + totMass * cog[0];
    cog[1] = mass * center[1] + totMass * cog[1];
    totMass += mass;
    cog[0] /= totMass;
    cog[1] /= totMass;
    if (i < vs - 1) {
      if ((cog[0] < v[i + 1][0] && cog[0] < v[i + 1][2]) ||
          (cog[0] > v[i + 1][0] && cog[0] > v[i + 1][2]) ||
          (cog[1] > v[i + 1][1] && cog[1] > v[i + 1][3]) ||
          (cog[1] > v[i + 1][1] && cog[1] > v[i + 1][3])) {
        return true;
      }
    } else {
      if ((cog[0] < v[i][0] && cog[0] < v[i][2]) ||
          (cog[0] > v[i][0] && cog[0] > v[i][2]) ||
          (cog[1] > v[i][1] && cog[1] > v[i][3]) ||
          (cog[1] > v[i][1] && cog[1] > v[i][3])) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  vector<vector<float> > v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<float> vv;
    int p;
    for (int ii = 0; ii < 4; ii++) {
      cin >> p;
      vv.push_back((float)p);
    }
    v.insert(v.begin(), vv);
    if (collapses(v)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
}
