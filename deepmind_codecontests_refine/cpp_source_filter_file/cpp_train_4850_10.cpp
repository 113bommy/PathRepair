#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9 + 7);
int n, k, ans;
string s;
vector<int> choco;
bool check(int ans) {
  int l = 0, r = 1;
  vector<int> v;
  v.push_back(0);
  while (r < choco.size()) {
    while (choco[r] - choco[l] - 1 <= ans && r < choco.size()) r++;
    if (r - 1 == l) return false;
    l = r - 1;
    v.push_back(l);
  }
  if (v.back() + 1 == choco.size()) return v.size() <= k;
  return false;
}
int main() {
  cin >> n >> k >> s;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') choco.push_back(i);
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
