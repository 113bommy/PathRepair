#include <bits/stdc++.h>
using namespace std;
string s[100005];
map<int, int> m;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int len = s[i].length();
    int tmp = 0;
    for (int j = 0; j < len; j++) {
      tmp ^= 1 << (s[i][j] - 'a');
    }
    m[tmp]++;
  }
  map<int, int>::iterator it = m.begin();
  long long ans = 0;
  for (; it != m.end(); it++) {
    ans += it->second * (it->second - 1);
    int tmp = it->first;
    for (int i = 0; i < 26; i++) {
      if (m.count(tmp ^ (1 << i))) ans += 1ll * it->second * m[tmp ^ (1 << i)];
    }
  }
  ans /= 2;
  cout << ans << endl;
}
