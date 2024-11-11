#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, t = 0;
  cin >> n;
  unordered_map<string, int> m;
  for (int i = -1; i < n; i++) {
    string x;
    getline(cin, x);
    m[x] = --t;
  }
  vector<pair<int, string> > a;
  for (auto x : m) {
    a.push_back({x.second, x.first});
  }
  sort(a.begin(), a.end());
  for (auto x : a) {
    printf("%s\n", x.second.c_str());
  }
}
