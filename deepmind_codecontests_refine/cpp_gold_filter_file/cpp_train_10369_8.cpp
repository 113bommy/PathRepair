#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, l, r, xp = 1, yp = 1, maxn, temp1, temp2;
  cin >> x >> y >> l >> r;
  vector<long long int> xv;
  vector<long long int> yv;
  vector<long long int> nv;
  while (r / x >= xp) {
    xv.push_back(xp);
    xp *= x;
  }
  xv.push_back(xp);
  while (r / y >= yp) {
    yv.push_back(yp);
    yp *= y;
  }
  yv.push_back(yp);
  for (int i = 0; i < xv.size(); i++) {
    temp1 = xv[i];
    for (int j = 0; j < yv.size(); j++) {
      temp2 = yv[j];
      if (temp1 + temp2 >= l && temp1 + temp2 <= r) nv.push_back(temp1 + temp2);
    }
  }
  nv.push_back(l - 1);
  nv.push_back(r + 1);
  sort(nv.begin(), nv.end());
  maxn = 0;
  for (int i = 1; i < nv.size(); i++) {
    maxn = max(maxn, (nv[i] - nv[i - 1]));
  }
  cout << maxn - 1;
}
