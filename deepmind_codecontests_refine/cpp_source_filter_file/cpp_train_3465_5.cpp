#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, l = -1, r = -1, c = 0, ans = 0;
    cin >> a >> b;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == '1') {
        l = i;
        break;
      }
    for (int i = s.length() - 1; i >= 0; i--)
      if (s[i] == '1') {
        r = i;
        break;
      }
    if (l == -1 && r == -1) {
      cout << "0/n";
      continue;
    }
    for (int i = l; i <= r; i++) {
      if (s[i] == '0')
        c++;
      else {
        v.push_back(c);
        c = 0;
      }
    }
    ans = a;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] * b < a)
        ans += (v[i] * b);
      else
        ans += a;
    }
    cout << ans << "\n";
  }
}
