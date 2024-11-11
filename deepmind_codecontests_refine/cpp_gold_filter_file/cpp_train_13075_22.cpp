#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;
  int id = 10000;
  vector<int> ve;
  for (int i = 0; i <= (int)b.length() - a.length(); i++) {
    string k = b.substr(i, a.length());
    int diff = 0;
    vector<int> diffs;
    for (int j = 0; j < (int)a.length(); j++) {
      if (a[j] != k[j]) {
        diff++;
        diffs.push_back(j + 1);
      }
    }
    if (diff < id) {
      id = diff;
      ve = diffs;
    }
  }
  cout << id << '\n';
  for (int i : ve) cout << i << ' ';
  return 0;
}
