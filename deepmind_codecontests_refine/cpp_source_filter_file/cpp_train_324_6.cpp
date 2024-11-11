#include <bits/stdc++.h>
using namespace std;
int minimum = 1e9;
bool cmp(int a, int b) { return a > b; }
void dfs(vector<int> v, bool flag) {
  if (v.size() == 0 || minimum == 0) {
    minimum = 0;
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    if (flag == true) {
      if (v[i] % 2 == 0) {
        v.erase(v.begin() + i);
        dfs(v, false);
        return;
      }
    } else {
      if (v[i] % 2 == 1) {
        v.erase(v.begin() + i);
        dfs(v, true);
        return;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  minimum = min(minimum, sum);
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n;
  int inp;
  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    v.push_back(inp);
  }
  sort(v.begin(), v.end(), cmp);
  dfs(v, true);
  dfs(v, false);
  cout << minimum << "\n";
}
