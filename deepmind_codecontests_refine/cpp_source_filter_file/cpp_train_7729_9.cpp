#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  for (int i = int(0); i < int(t); ++i) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for (int j = int(0); j < int(m); ++j) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[b].push_back(a);
    }
    vector<int> num(n, -1);
    num[0] = 0;
    for (int j = int(1); j < int(n); ++j) {
      bool zero, one, two;
      zero = one = two = false;
      for (auto from : g[j]) {
        if (num[from] == 0) {
          zero = true;
        } else if (num[from] == 1) {
          one = true;
        } else {
          two = true;
        }
      }
      if (one) {
        num[j] = 2;
      } else if (zero) {
        num[j] = 1;
      } else if (two) {
        num[j] = 0;
      }
    }
    vector<int> ans;
    for (int j = int(0); j < int(n); ++j) {
      if (num[j] == 2) ans.push_back(j + 1);
    }
    cout << ans.size() << endl;
    for (int j = int(0); j < int(ans.size()); ++j) {
      if (j) cout << " ";
      cout << ans[j];
    }
    cout << endl;
  }
}
