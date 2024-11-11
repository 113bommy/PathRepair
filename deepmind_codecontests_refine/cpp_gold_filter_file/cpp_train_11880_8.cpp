#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  if (fopen("input.in", "r"))
    freopen("input.in", "r", stdin), freopen("output.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> res;
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  int cur = n - 1;
  while (cur != 0) {
    res.push_back(cur);
    cur = p[cur];
  }
  res.push_back(0);
  reverse(res.begin(), res.end());
  for (int i : res) cout << i + 1 << " ";
}
