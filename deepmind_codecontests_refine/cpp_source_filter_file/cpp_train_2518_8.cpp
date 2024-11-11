#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
char s[4005], t[4005];
int a[4005], b[4005];
int cta[4005][4], ctb[4005][4];
void doit(int *a, int pl) {
  reverse(a + 1, a + pl + 1);
  for (int i = 1; i <= pl; i++)
    if (a[i] == 1 || a[i] == 2) a[i] = 3 - a[i];
}
vector<int> ans;
void getans(int x) {
  if (x <= 0) return;
  ans.push_back(x);
  doit(a, x);
}
void work() {
  ans.clear();
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n / 2; i++) {
    a[i] = (s[i * 2 - 1] - '0') * 2 + (s[i * 2] - '0');
    b[i] = (t[i * 2 - 1] - '0') * 2 + (t[i * 2] - '0');
  }
  n /= 2;
  for (int i = 1; i <= n; i++)
    if (b[i] == 1 || b[i] == 2) b[i] = 3 - b[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) cta[i][j] = cta[i - 1][j];
    cta[i][a[i]]++;
    for (int j = 0; j < 4; j++) ctb[i][j] = ctb[i - 1][j];
    ctb[i][b[i]]++;
  }
  if (cta[n][0] != ctb[n][0]) {
    cout << "-1\n";
    return;
  }
  if (cta[n][3] != ctb[n][3]) {
    cout << "-1\n";
    return;
  }
  if (cta[n][1] + cta[n][2] != ctb[n][1] + ctb[n][2]) {
    cout << "-1\n";
    return;
  }
  int Tag = 0;
  if (cta[n][1] != ctb[n][1]) {
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      int D = cta[i][1] - cta[i][2];
      if (cta[n][1] + D == ctb[n][1]) {
        ok = 1;
        ans.push_back(i);
        doit(a, i);
        break;
      }
    }
    if (!ok) {
      for (int i = 1; i <= n; i++) {
        int D = ctb[i][1] - ctb[i][2];
        if (ctb[n][1] + D == cta[n][1]) {
          ok = 1;
          doit(b, i);
          Tag = i;
          break;
        }
      }
    }
    assert(ok);
  }
  for (int i = 1; i <= n; i++) {
    int o = b[n - i + 1], pl = 0;
    for (int j = i; j <= n; j++) {
      if (a[j] == o) {
        pl = j;
        break;
      }
    }
    getans(pl - 1);
    getans(pl);
  }
  if (Tag) getans(Tag);
  cout << ans.size() << endl;
  for (int i : ans) printf("%d ", i * 2);
  cout << "\n";
}
signed main() {
  int T = read();
  while (T--) work();
  return 0;
}
