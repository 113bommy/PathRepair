#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[105], b[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll i, j;
  string s;
  cin >> s;
  vector<int> pos;
  for (i = 0, j = (int)s.size() - 1; i < j;) {
    while (s[i] == ')') i++;
    while (j >= 0 && s[j] == '(') j--;
    if (i > j) break;
    pos.push_back(i);
    pos.push_back(j);
    i++;
    j--;
  }
  sort(pos.begin(), pos.end());
  if (pos.empty()) return cout << 0, 0;
  cout << "1\n" << pos.size() << '\n';
  for (int x : pos) cout << x + 1 << ' ';
}
