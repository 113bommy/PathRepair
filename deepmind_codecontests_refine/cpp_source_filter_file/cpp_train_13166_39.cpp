#include <bits/stdc++.h>
using namespace std;
const int maxN = 100010;
int n, m, a[maxN], f[30][maxN];
long long res, S[maxN];
char s[maxN];
struct ioi {
  int v, p;
};
ioi c[maxN];
bool cmp(ioi i, ioi j) { return i.v < j.v; }
int main() {
  for (int i = 0; i <= 25; ++i) scanf("%d", &a[i]);
  scanf("\n");
  scanf("%s\n", &s);
  int len = strlen(s), num = 0;
  for (int i = 1; i <= len; ++i) {
    S[i] = S[i - 1] + a[s[i - 1] - 'a'];
    c[++num].v = S[i];
    c[num].p = i;
  }
  sort(c + 1, c + num + 1, cmp);
  int val = 1;
  S[c[1].p] = val;
  for (int i = 2; i <= num; ++i) {
    val += (c[i].v != c[i - 1].v);
    S[c[i].p] = val;
  }
  f[s[0] - 'a'][S[1]] = 1;
  for (int i = 2; i <= len; ++i) {
    res += (f[s[i - 1] - 'a'][S[i - 1]]);
    f[s[i - 1] - 'a'][S[i]]++;
  }
  cout << res;
  fclose(stdin);
  fclose(stdout);
}
