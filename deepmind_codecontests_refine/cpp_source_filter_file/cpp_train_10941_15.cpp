#include <bits/stdc++.h>
using namespace std;
int maxl = 100005;
bool check(string s) {
  if ((s.find("A") != string::npos) && (s.find("B") != string::npos) &&
      (s.find("C") != string::npos))
    return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int ans;
  cin >> n;
  vector<pair<int, string> > v(n);
  int c;
  bool ca, cb, cc;
  ca = cb = cc = false;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> c >> s;
    v[i].first = c;
    v[i].second = s;
  }
  int minA, minB, minC, minAB, minBC, minAC, minABC;
  minA = minB = minC = minAB = minBC = minAC = minABC = maxl;
  for (int i = 0; i < n; i++) {
    if (v[i].second == "A") {
      ca = true;
      minA = min(minA, v[i].first);
    } else if (v[i].second == "B") {
      cb = true;
      minB = min(minB, v[i].first);
    } else if (v[i].second == "C") {
      cc = true;
      minC = min(minC, v[i].first);
    } else if (v[i].second == "AB" || v[i].second == "BA") {
      ca = cb = true;
      minAB = min(minAB, v[i].first);
    } else if (v[i].second == "BC" || v[i].second == "CB") {
      cb = cc = true;
      minBC = min(minBC, v[i].first);
    } else if (v[i].second == "AC" || v[i].second == "CA") {
      ca = cc = true;
      minAC = min(minAC, v[i].first);
    } else if (check(v[i].second) == true) {
      ca = cb = cc = true;
      minABC = min(minABC, v[i].first);
    }
  }
  if (ca == false || cb == false || cc == false) {
    cout << "-1"
         << "\n";
    return 0;
  }
  ans = min(minA + minB + minC,
            min(minAB + minC, min(minBC + minA, min(minAC + minB, minABC))));
  ans = min(ans, min(minAB + minBC, min(minAB + minAC, minBC + minAC)));
  cout << ans << "\n";
}
