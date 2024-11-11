#include <bits/stdc++.h>
using namespace std;
vector<pair<string, char> > query;
void increment(string& str) {
  int ind = str.size() - 1;
  while (ind >= 0) {
    if (str[ind] != 'f') {
      char cur = str[ind] + 1;
      str[ind] = cur;
      return;
    } else {
      str[ind] = 'a';
      ind--;
    }
  }
  return;
}
bool tryans(string str) {
  string cur = str;
  while (cur.length() > 1) {
    bool diff = false;
    for (int i = 0; i < query.size(); ++i) {
      if (query[i].first == cur.substr(0, 2)) {
        cur = query[i].second + cur.substr(2, cur.size() - 2);
        diff = true;
        break;
      }
    }
    if (!diff) {
      break;
    }
  }
  if (cur == "a") {
    return true;
  }
  return false;
}
void solve(int n) {
  int q;
  cin >> q;
  query.resize(q);
  for (int i = 0; i < q; ++i) {
    cin >> query[i].first >> query[i].second;
  }
  long long ans = 0;
  string current;
  current.resize(n);
  for (int i = 0; i < current.size(); ++i) {
    current[i] = 'a';
  }
  for (int i = 0; i < pow(6, n) - 1; ++i) {
    if (tryans(current)) {
      ans++;
    }
    increment(current);
  }
  cout << ans << endl;
  return;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    solve(n);
  }
  return 0;
}
