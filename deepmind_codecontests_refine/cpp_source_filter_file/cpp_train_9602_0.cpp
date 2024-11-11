#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
const int N = 3e3 + 10;
bool a[N];
vector<vector<int>> vec;
vector<vector<int>> ans;
bool good(int id) { return a[id] == 1 && a[id + 1] == 0; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    a[i] = (ch == 'R');
  }
  int tot = 0;
  while (1) {
    vector<int> cur;
    for (int i = 1; i <= n - 1; i++) {
      if (good(i)) {
        cur.push_back(i);
      }
    }
    if (cur.empty()) {
      break;
    }
    tot += cur.size();
    vec.push_back(cur);
    for (int i : cur) {
      swap(a[i], a[i + 1]);
    }
  }
  if (k < vec.size() || tot < k) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < vec.size(); i++) {
    if (k > vec.size() - i) {
      int t = min(vec[i].size(), k - vec.size() - i - 1);
      for (int j = 0; j < t - 1; j++) {
        ans.push_back({vec[i][j]});
      }
      vector<int> cur;
      for (int j = t - 1; j < vec[i].size(); j++) {
        cur.push_back(vec[i][j]);
      }
      ans.push_back(cur);
      k -= t;
    } else {
      ans.push_back(vec[i]);
      k--;
    }
  }
  for (vector<int> cur : ans) {
    cout << cur.size() << " ";
    for (int i : cur) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
