#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s[1] == '1' && s[2] == '2') s[1] = s[2] = '0';
    int t = ((s[1] - '0') * 10 + (s[2] - '0')) * 60 +
            ((s[4] - '0') * 10 + (s[5] - '0'));
    if (s[7] == 'p') t += 12 * 60;
    v.push_back(t);
  }
  int ans = 1;
  for (int i = 1; i < v.size(); i++)
    if (v[i] < v[i - 1]) ans++;
  int p = 0;
  while (p < v.size()) {
    int q = p;
    while (v[p] == v[q]) q++;
    ans += (q - p - 1) / 10;
    p = q;
  }
  cout << ans << endl;
  return 0;
}
