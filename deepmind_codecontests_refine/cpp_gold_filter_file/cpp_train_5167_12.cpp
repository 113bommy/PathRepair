#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long t = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') t = t * 10 + c - 48, c = getchar();
  return t * f;
}
char s[200001];
int len, mi[2001], las[2001];
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 'a'; i <= 'z'; ++i) mi[i] = 0;
  for (int i = 1; i <= len; ++i) {
    if (!las[s[i]])
      las[s[i]] = i, mi[s[i]] = i;
    else
      mi[s[i]] = max(mi[s[i]], i - las[s[i]]), las[s[i]] = i;
  }
  for (int i = 'a'; i <= 'z'; ++i)
    if (mi[i]) mi[i] = max(mi[i], len - las[i] + 1);
  int ans = 1e9;
  for (int i = 'a'; i <= 'z'; ++i)
    if (mi[i]) ans = min(ans, mi[i]);
  cout << ans << endl;
}
