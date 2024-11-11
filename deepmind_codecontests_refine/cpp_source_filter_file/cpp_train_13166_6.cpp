#include <bits/stdc++.h>
using namespace std;
const int sigma = 26;
const int maxn = 100005;
int val[sigma];
int prefix[maxn];
map<unsigned long long, int> m[sigma];
string s;
int main() {
  memset(val, 0, sizeof val);
  for (int i = 0; i < sigma; i++) {
    cin >> val[i];
    m[i].clear();
  }
  cin >> s;
  int len = s.size();
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    char cc = s[i] - 'a';
    prefix[i] = i == 0 ? val[cc] : (prefix[i - 1] + val[cc]);
    if (i != 0) ans += m[cc][prefix[i - 1]];
    m[cc][prefix[i]]++;
  }
  cout << ans << endl;
  return 0;
}
