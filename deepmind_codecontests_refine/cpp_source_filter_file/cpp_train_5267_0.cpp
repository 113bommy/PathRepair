#include <bits/stdc++.h>
using namespace std;
const int maxn = 51;
string s[maxn], name[51];
string o[maxn];
int n, k, t;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n - k + 1; ++i) cin >> s[i];
  t = 50;
  for (int i = 1; i <= 26; ++i) name[i] += (char)('A' + i - 1);
  for (int i = 27; i <= 50; ++i) {
    name[i] += (char)('A' + i - 1);
    name[i] += (char)('a' + i - 27);
  }
  for (int i = n; i >= n - k + 2; --i) o[i] = name[t--];
  for (int i = n - k + 1; i >= 1; --i)
    if (s[i][0] == 'Y')
      o[i] = name[t--];
    else
      o[i] = o[i + k - 1];
  for (int i = 1; i <= n; ++i) cout << o[i] << ' ';
  return 0;
}
