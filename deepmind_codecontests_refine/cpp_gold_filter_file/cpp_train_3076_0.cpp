#include <bits/stdc++.h>
using namespace std;
using namespace std;
int ar[502], used[502], pre[502], d[502], c[502], tmp[502], was[502][502], n, k;
vector<int> vec[505], ans;
void dfs(int r, vector<int> vc) {
  bool flag = 0;
  for (int i = 0; i < (int)(vc).size(); i++) {
    if (was[r][vc[i]] == 0) flag = 1;
  }
  if (!flag && r != k) return;
  for (int i = 0; i <= 500; i++) c[i] = 0;
  for (int i = 0; i < (int)(vc).size(); i++) {
    was[r][vc[i]] = 1;
    c[vc[i]]++;
    if (c[vc[i]] > d[vc[i]]) {
      return;
    }
  }
  for (auto x : vec[r]) {
    vc.push_back(x);
    dfs(r - x, vc);
    vc.pop_back();
  }
  for (int j = 1; j <= 500; j++) used[j] = 0, tmp[j] = 0;
  if ((int)(vec[r]).size() == 0) {
    for (auto each : vc) {
      tmp[each] = 1;
      for (int j = 1; j <= 500; j++) {
        if (used[j] == 1) {
          tmp[j + each] = 1;
        }
      }
      for (int j = 1; j <= 500; j++) {
        if (tmp[j]) {
          used[j] = 1;
          ans[j] = 1;
        }
      }
      for (int j = 1; j <= 500; j++) tmp[j] = 0;
    }
  }
}
int main() {
  cin >> n >> k;
  ans.resize(510);
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  used[0] = 1;
  for (int i = 0; i < n; i++) {
    int a = ar[i];
    d[a]++;
    for (int j = 1; j <= 500; j++) pre[j] = 0;
    pre[ar[i]] = 1;
    for (int j = 0; j < 500; j++) {
      if (used[j] == 1) {
        if (j + a <= 500) pre[j + a] = 1;
      }
    }
    for (int j = 1; j <= 500; j++) {
      if (pre[j]) {
        used[j] = 1;
        vec[j].push_back(a);
      }
    }
  }
  for (int j = 1; j <= 500; j++) used[j] = 0;
  vector<int> vc, ans1;
  dfs(k, vc);
  ans1.push_back(0);
  for (int i = 1; i <= 500; i++) {
    if (i <= k && ans[i]) ans1.push_back(i);
  }
  cout << (int)(ans1).size() << '\n';
  for (auto x : ans1) {
    cout << x << " ";
  }
}
