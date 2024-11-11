#include <bits/stdc++.h>
using namespace std;
int FindMid(vector<int> v) {
  sort(v.begin(), v.end());
  return v[1];
}
int dir(int a) { return a < 0 ? -1 : 1; }
int main() {
  ifstream D("duom.txt");
  ofstream R("rez.txt");
  vector<pair<int, int> > eile;
  vector<int> xk(3);
  vector<int> yk(3);
  for (int i = 0; i < 3; ++i) cin >> xk[i] >> yk[i];
  int midx = FindMid(xk);
  int midy = FindMid(yk);
  eile.push_back({midx, midy});
  for (int i = 0; i < 3; i++) {
    int x = xk[i];
    int y = yk[i];
    while (x != midx) {
      eile.push_back({x, y});
      x += dir(midx - x);
    }
    while (y != midy) {
      eile.push_back({x, y});
      y += dir(midy - y);
    }
  }
  cout << eile.size();
  cout << endl;
  for (pair<int, int> a : eile) cout << a.first << ' ' << a.second << endl;
  cin.get();
  return 0;
}
