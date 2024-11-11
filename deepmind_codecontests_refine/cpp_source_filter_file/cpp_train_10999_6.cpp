#include <bits/stdc++.h>
using namespace std;
int a, x, y;
vector<pair<pair<int, int>, int> > X;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> x >> y;
    X.push_back(make_pair(make_pair(x, y), i));
  }
  sort(X.begin(), X.end());
  for (int i = 1; i < X.size(); i++)
    if (X[i].first.second <= X[i - 1].first.second) {
      cout << X[i].second << " " << X[i - 1].second;
      return 0;
    }
  cout << "-1 -1";
  return 0;
}
