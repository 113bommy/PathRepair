#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 9;
const int INF = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
int n;
int solve(vector<int> v, int j = 3) {
  vector<int> l, r;
  if (j == -1) return v[0];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] & (1 << j))
      l.push_back(v[i]);
    else
      r.push_back(v[i]);
  }
  if (0) {
    cout << j << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
  }
  if (l.size() == 0) return solve(r, j - 1);
  if (r.size() == 0) return ((1 << j) ^ solve(l, j - 1));
  return min(solve(l, j - 1), solve(r, j - 1) ^ (1 << j));
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  if (0)
    ;
  else
    cin.tie(NULL), cout.tie(NULL);
  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  cout << solve(v);
  return 0;
}
