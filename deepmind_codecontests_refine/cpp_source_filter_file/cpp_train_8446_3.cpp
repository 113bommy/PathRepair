#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
int check(string s) {
  int n = s.size();
  if (n >= 4 and s.substr(n - 4, 4) == "lios") {
    return 1;
  } else if (n >= 4 and s.substr(n - 4, 4) == "etra") {
    return 4;
  } else if (n >= 3 and s.substr(n - 3, 3) == "etr") {
    return 3;
  } else if (n >= 5 and s.substr(n - 5, 5) == "liala") {
    return 2;
  } else if (n >= 6 and s.substr(n - 6, 6) == "initis") {
    return 5;
  } else if (n >= 6 and s.substr(n - 6, 6) == "inites") {
    return 6;
  } else {
    return 0;
  }
}
void code() {
  string s;
  vector<string> v;
  while (cin >> s) v.push_back(s);
  if (v.size() == 1) {
    cout << (check(v.front()) ? "YES\n" : "NO\n");
    return;
  }
  int st = check(v.front());
  int gender = (st & 1);
  vector<int> noun;
  noun.push_back(-1);
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = check(v[i]);
    if ((x + 1) / 2 == 2) cnt++, noun.push_back(i);
  }
  noun.push_back(v.size());
  if (cnt != 1 or (check(v[noun[1]]) & 1) != (st & 1)) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < noun[1]; i++) {
    int x = check(v[i]);
    if (x & 1 != st & 1) {
      cout << "NO\n";
      return;
    }
    if ((x + 1) / 2 != 1) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = noun[1] + 1; i < v.size(); i++) {
    int x = check(v[i]);
    if (x & 1 != st & 1) {
      cout << "NO\n";
      return;
    }
    if ((x + 1) / 2 != 3) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
