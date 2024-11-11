#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int>::iterator ite;
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') v.push_back(i);
  }
  int mn = 1e6;
  for (int i = k; i < v.size(); i++) {
    int B = v[i - k];
    int E = v[i];
    int mid = (v[i] - v[i - k]) + 1;
    ite = lower_bound(v.begin(), v.end(), B + mid / 2);
    int pos1 = *ite;
    int pos2 = *(--ite);
    int res1 = max(pos1 - B, E - pos1);
    int res2 = max(pos2 - B, E - pos2);
    mn = min(res1, res2);
  }
  cout << mn;
  return 0;
}
