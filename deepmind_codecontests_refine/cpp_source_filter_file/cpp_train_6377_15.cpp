#include <bits/stdc++.h>
using namespace std;
int sp[200000 + 10], poz[200000 + 10];
string s;
vector<pair<int, int> > a;
pair<int, int> ans;
bool v[200000 + 10];
int binSearch(int val, int m) {
  int st = 1, dr = m;
  while (st <= dr) {
    int mij = (st + dr) / 2;
    if (val > a[mij].first)
      st = mij + 1;
    else
      dr = mij - 1;
  }
  return st;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
        s[i] == 'O' || s[i] == 'U')
      v[i + 1] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (v[i])
      sp[i] = sp[i - 1] - 1;
    else
      sp[i] = sp[i - 1] + 2;
    a.push_back({sp[i], i});
  }
  sort(a.begin(), a.end());
  a.push_back({2000000000, -1});
  int m = a.size();
  for (int i = m - 1; i >= 0; i--) poz[i] = max(poz[i + 1], a[i].second);
  int curr = 0;
  for (int i = 1; i <= n; i++) {
    int p = binSearch(curr, m), l = poz[p] - i + 1;
    if (l > ans.first)
      ans = {l, 1};
    else if (l == ans.first)
      ans.second++;
    if (v[i])
      curr--;
    else
      curr += 2;
  }
  if (!ans.first)
    cout << "No solution" << '\n';
  else
    cout << ans.first << ' ' << ans.second << '\n';
  return 0;
}
