#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int v[555];
set<int> ss;
int main() {
  int a, b, l, r;
  cin >> a >> b >> l >> r;
  if (r - l + 1 >= (a + b) * 2)
    cout << a + max(a - b, 1) << endl;
  else {
    int ans = 999;
    l--;
    r--;
    for (int j = 0; j < a; j++) {
      memset(v, 0, sizeof v);
      string s = "";
      for (int i = 0; i < a; i++) {
        s.push_back(i + 'a');
      }
      for (int i = 0; i < b; i++) {
        s.push_back(j + 'a');
      }
      int len = ((int)(s).size());
      for (int i = len - a; i < len; i++) {
        v[s[i] - 'a'] = 1;
      }
      for (int i = 0, j = 0; i < a; i++) {
        while (v[j]) j++;
        s.push_back(j + 'a');
        v[j] = 1;
      }
      string str = s;
      for (int k = a; k < 26; k++) {
        s = str;
        for (int i = 0; i < b; i++) {
          s.push_back(k + 'a');
        }
        int m = (a + b) * 2;
        ss.clear();
        for (int i = l; i <= r; i++) {
          ss.insert(s[i % m]);
        }
        ans = min(ans, ((int)(ss).size()));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
