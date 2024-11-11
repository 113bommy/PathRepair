#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char **argv) {
  if (argc == 2) {
    freopen(argv[1], "r", stdin);
  }
  vector<int> ans;
  int n, m;
  cin >> n >> m;
  set<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.insert(x);
  }
  for (int i = 1; i < 1e9; i++) {
    if (i > m) {
      break;
    }
    if (v.find(i) == v.end()) {
      m -= i;
      ans.emplace_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
