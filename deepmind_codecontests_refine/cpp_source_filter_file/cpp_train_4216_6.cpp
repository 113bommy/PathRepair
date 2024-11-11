#include <bits/stdc++.h>
using namespace std;
int a[1000010];
char res[1000010];
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  int N, M;
  cin >> N >> M;
  string s;
  cin >> s;
  vector<int> z = z_function(s + "#" + s);
  for (int i = 0; i < M; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= N; i++) res[i] = '*';
  int cur = 0;
  for (int i = 0; i < M; i++) {
    if (!i || a[i - 1] + (int)s.length() < a[i]) {
      for (int j = 0; j < (int)s.length(); j++) res[a[i] + j] = s[j];
    } else {
      int len = (int)s.length() - (a[i] - a[i - 1]);
      if (z[(int)s.length() + (int)s.length() - len + 1] == len) {
        for (int j = len; j < (int)s.length(); j++) res[a[i] + j] = s[j];
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  long long cnt = 1, mod = 1e9 + 7;
  for (int i = 1; i <= N; i++) {
    if (res[i] == '*') cnt = (cnt * 26) % mod;
  }
  cout << cnt << endl;
  return 0;
}
