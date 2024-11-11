#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long f[110][110];
long long n, k;
char s[110];
long long ch2i[225];
long long ich2i[110][225];
int main() {
  cin >> n >> k;
  scanf("%s", s);
  for (int i = 'a'; i < 'z' + 1; i++) {
    ch2i[i] = -1;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int ch = 'a'; ch < 'z' + 1; ch++) {
      ich2i[i][ch] = ch2i[ch];
    }
    ch2i[s[i]] = i;
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    f[i][1] = 1;
  }
  for (int len = 2; len < n + 1; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      for (int j = i + 1; j < n - len + 2; j++) {
        if (ich2i[i][s[j]] != j) continue;
        f[i][len] += f[j][len - 1];
      }
    }
  }
  long long cnt = 0;
  long long ans = 0;
  for (int len = n + 1 - 1; len >= 0; len--) {
    for (int i = 0; i < n - len + 1; i++) {
      if (i != ch2i[s[i]]) continue;
      cnt += f[i][len];
      ans += (n - len) * f[i][len];
      if (cnt >= k) {
        ans -= (cnt - k) * (n - len);
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
