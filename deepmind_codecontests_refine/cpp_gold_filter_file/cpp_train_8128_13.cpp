#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int INF = int(1e9);
set<char> st;
int cnt[N], k, n;
char s[N], m[N];
int main() {
  gets(s);
  cin >> k;
  n = strlen(s);
  for (int i = 0; i < n; ++i) cnt[int(s[i])]++;
  while (k) {
    int Min = INF, q;
    for (int ch = 'a'; ch <= 'z'; ++ch)
      if (cnt[ch] > 0) {
        if (cnt[ch] < Min) {
          Min = cnt[ch];
          q = char(ch);
        }
      }
    if (Min <= k) {
      cnt[q] -= Min;
      m[q] = true;
      k -= Min;
    } else
      break;
  }
  for (int k = 0; k < n; ++k)
    if (m[int(s[k])] == 0) st.insert(s[k]);
  cout << st.size() << '\n';
  for (int tt = 0; tt < n; ++tt)
    if (m[int(s[tt])] == 0) cout << s[tt];
  cout << '\n';
}
