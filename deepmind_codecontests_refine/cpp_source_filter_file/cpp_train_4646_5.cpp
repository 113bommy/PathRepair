#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pair<pair<int, int>, int>> vect;
  int n;
  cin >> n;
  vect.push_back(make_pair(make_pair(-1, -1), 0));
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    vect.push_back(make_pair(make_pair(l, r), i));
  }
  sort(vect.begin(), vect.end());
  for (int i = 1; i < n; i++) {
    if (vect[i].first.first == vect[i + 1].first.first) {
      cout << vect[i].second << endl;
      return 0;
    }
    if (vect[i].first.second >= vect[i + 1].first.second) {
      cout << vect[i].second << endl;
      return 0;
    }
    if (vect[i - 1].first.second >= vect[i].first.first &&
        vect[i - 1].first.second >= vect[i + 1].first.first &&
        vect[i].first.second <= vect[i + 1].first.second) {
      cout << vect[i].second << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
}
