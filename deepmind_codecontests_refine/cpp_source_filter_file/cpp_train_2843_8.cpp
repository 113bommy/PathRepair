#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:25600000")
using namespace std;
const long doublepi = acos(-1.0);
vector<int> zfunc(string& s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  string s;
  cin >> s;
  int ans = 0;
  int n;
  cin >> n;
  for (long long www = 0; www < n; www++) {
    string word;
    cin >> word;
    string s1 = word + "#" + s;
    string s2 = s + "#" + word;
    reverse((s2).begin(), (s2).end());
    vector<int> z1 = zfunc(s1);
    vector<int> z2 = zfunc(s2);
    vector<int> mn1(word.size() + 1, 1000000);
    vector<int> mn2(word.size() + 1, 1000000);
    mn1[0] = mn2[0] = 0;
    for (int i = word.size() + 1; i <= z1.size() - 1; i++) {
      mn1[z1[i]] = min(int(i - word.size() - 1), mn1[z1[i]]);
      mn2[z2[i]] = min(int(i - word.size() - 1), mn1[z1[i]]);
    }
    for (int j = mn1.size() - 1; j >= 0; --j)
      if (j) {
        mn1[j - 1] = min(mn1[j - 1], mn1[j]);
        mn2[j - 1] = min(mn2[j - 1], mn2[j]);
      }
    bool ok = false;
    for (int l = 1; l <= word.size() - 1; l++)
      if (mn1[l] + mn2[word.size() - l] + word.size() <= s.size()) ok = true;
    ans += ok;
  }
  cout << ans << endl;
}
