#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:60000000");
vector<int> solve(int num, int k) {
  vector<int> ans;
  ans.push_back(num);
  ans.push_back(-num);
  for (int cnt = 1, mod = 10; cnt < k; ++cnt, mod *= 10) {
    vector<int> a = solve(num / mod, k - cnt);
    vector<int> b = solve(num % mod, cnt);
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        ans.push_back(a[i] + b[j]);
        ans.push_back(a[i] * b[j]);
        ans.push_back(a[i] - b[j]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  return ans;
}
int main() {
  int k, m;
  cin >> k >> m;
  for (int i = 0; m && i < 10000; ++i) {
    vector<int> v = solve(i, 4);
    for (int j = 0; j < v.size(); ++j) {
      int x = v[j];
      if (k - x >= 0 && k - x < 10000) {
        printf("%04d%04d\n", k - x, i);
        m--;
      }
    }
  }
  return 0;
}
