#include <bits/stdc++.h>
using namespace std;
int n;
string s, ans[200];
vector<pair<int, string> > v;
bool cmp(pair<int, string> x, pair<int, string> y) {
  return x.second.length() < y.second.length();
}
bool ok(string x, string y) {
  for (int i = x.length() - 1, j = y.length() - 1; j > -1; j--, i--) {
    if (x[i] != y[j]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  bool b = 1;
  cin >> n;
  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> s;
    v.push_back({i + 1, s});
  }
  if (n == 2) {
    cout << "PS\n";
    return 0;
  }
  sort(v.begin(), v.end(), cmp);
  ans[v[v.size() - 1].first] = "P";
  ans[v[v.size() - 2].first] = "S";
  string x = v[v.size() - 1].second;
  string y = v[v.size() - 2].second;
  for (int i = 0; i < v.size() - 2; i += 2) {
    if (x.find(v[i].second) != string::npos && x.find(v[i].second) == 0 &&
        ok(y, v[i + 1].second)) {
      ans[v[i].first] = "P";
      ans[v[i + 1].first] = "S";
    } else if (x.find(v[i + 1].second) != string::npos &&
               x.find(v[i + 1].second) == 0 && ok(y, v[i].second)) {
      ans[v[i + 1].first] = "P";
      ans[v[i].first] = "S";
    } else {
      b = 0;
      break;
    }
  }
  if (b) {
    for (int i = 1; i <= 2 * n - 2; i++) {
      cout << ans[i];
    }
    cout << endl;
    return 0;
  }
  ans[v[v.size() - 1].first] = "S";
  ans[v[v.size() - 2].first] = "P";
  for (int i = 0; i < v.size() - 2; i += 2) {
    if (y.find(v[i].second) != string::npos && y.find(v[i].second) == 0 &&
        ok(x, v[i + 1].second)) {
      ans[v[i].first] = "P";
      ans[v[i + 1].first] = "S";
    } else {
      ans[v[i].first] = "S";
      ans[v[i + 1].first] = "P";
    }
  }
  for (int i = 1; i <= 2 * n - 2; i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
