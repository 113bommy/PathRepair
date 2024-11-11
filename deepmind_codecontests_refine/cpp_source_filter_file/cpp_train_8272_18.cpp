#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[1000010];
int pi[1000010];
int z[1000010];
int per[1000010];
void pf() {
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
}
void zf() {
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
int ans[1000010];
char a[1000010];
int main() {
  scanf("%d%d%s", &n, &k, s);
  if (static_cast<int>(strlen(s)) != n) {
    cerr << strlen(s) << endl;
    throw logic_error("invalid input");
  }
  pf();
  zf();
  for (int i = 0; i < n; ++i) {
    const int x = i + 1 - pi[i];
    if ((i + 1) % x == 0) {
      per[i] = x;
    } else {
      per[i] = i + 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (((i + 1) / per[i]) % k == 0) {
      ans[i] = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    const int curz = min(z[i], i / k);
    if (((i + 0) / per[i - 1]) % k == 0) {
      ans[i + curz - 1] = max(ans[i + curz - 1], curz);
    }
  }
  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur = max(cur, ans[i]);
    if (cur > 0)
      a[i] = '1';
    else
      a[i] = '0';
    --cur;
  }
  printf("%s\n", a);
  return 0;
}
