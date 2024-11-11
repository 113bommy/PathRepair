#include <bits/stdc++.h>
using namespace std;
bool cmp(const int &a, const int &b) { return a > b; }
int main() {
  vector<int> vf, vs, vans;
  char cc;
  int c, sum1 = 0, sum2 = 0, sumans, sumcmp, num = 0;
  for (int i = 0; i < 3; i++) {
    cin >> cc;
    c = cc - '0';
    sum1 += c;
    vf.push_back(c);
  }
  for (int i = 0; i < 3; i++) {
    cin >> cc;
    c = cc - '0';
    sum2 += c;
    vs.push_back(c);
  }
  if (sum1 < sum2) {
    sumans = sum2 - sum1;
    for (int i = 0; i < 3; i++) {
      c = 9 - vf[i];
      vans.push_back(c);
      c = vs[i] - 0;
      vans.push_back(c);
    }
    sort(vans.begin(), vans.end(), cmp);
    sumcmp = 0;
    for (int i = 0; i < vans.size(); i++) {
      sumcmp += vans[i];
      num++;
      if (sumcmp >= sumans) break;
    }
  } else if (sum1 > sum2) {
    sumans = sum1 - sum2;
    for (int i = 0; i < 3; i++) {
      c = vf[i] - 0;
      vans.push_back(c);
      c = 9 - vs[i];
      vans.push_back(c);
    }
    sort(vans.begin(), vans.end(), cmp);
    sumcmp = 0;
    for (int i = 0; i < vans.size(); i++) {
      sumcmp += vans[i];
      num++;
      if (sumcmp >= sumans) break;
    }
  }
  cout << num;
  return 0;
}
