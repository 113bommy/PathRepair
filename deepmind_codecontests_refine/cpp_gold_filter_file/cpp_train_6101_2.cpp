#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
char s[maxn];
char ans[maxn];
set<int> st;
int main() {
  for (int i = 0; i <= maxn; i++) st.insert(i);
  memset(ans, 0, sizeof(ans));
  int mx = 0;
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", s);
    int len = strlen(s);
    int t;
    scanf("%d", &t);
    while (t--) {
      int x;
      scanf("%d", &x);
      x--;
      auto it = st.lower_bound(x);
      while (it != st.end()) {
        if (*it - x >= len) break;
        ans[(*it)] = s[(*it) - x];
        it = st.erase(it);
      }
      mx = max(mx, x + len - 1);
    }
  }
  for (int i = 0; i < mx; i++) {
    if (ans[i] == 0) ans[i] = 'a';
  }
  puts(ans);
  return 0;
}
