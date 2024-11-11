#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int nP;
  cin >> nP;
  vector<int> X, Y;
  set<pair<int, int> > p;
  for (int i = 1; i <= nP; ++i) {
    int x, y;
    cin >> x >> y;
    X.push_back(x);
    Y.push_back(y);
    p.insert(make_pair(x, y));
  }
  int count = 0;
  for (int i = 0; i < nP - 2; ++i) {
    for (int j = i + 2; j < nP; ++j) {
      if ((X[i] + X[j]) % 2 == 0 && (Y[i] + Y[j]) % 2 == 0) {
        int halfX = (X[i] + X[j]) / 2;
        int halfY = (Y[i] + Y[j]) / 2;
        if (p.find(make_pair(halfX, halfY)) != p.end()) {
          ++count;
        }
      }
    }
  }
  cout << count << "\n";
}
