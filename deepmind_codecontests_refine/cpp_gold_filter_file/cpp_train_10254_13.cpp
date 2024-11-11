#include <bits/stdc++.h>
using namespace std;
inline int IN() {
  char ch = getchar();
  int f = 1, x = 0;
  while (((ch) == '\n' || (ch) == '\r' || (ch) == '\t' || (ch) == ' '))
    ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (!((ch) == '\n' || (ch) == '\r' || (ch) == '\t' || (ch) == ' '))
    x = x * 10 + ch - '0', ch = getchar();
  return x *= f;
}
char a[200005], b[200005];
int cnt;
map<pair<int, int>, int> Mps;
map<unsigned long long, int> lef;
int work(char *a, int l, int r) {
  if ((r - l + 1) & 1) {
    unsigned long long re = 0;
    for (int i = (int)l; i <= (int)r; i++) (re *= 233ll) += a[i] - 'a';
    int &v = lef[re];
    if (!v) v = ++cnt;
    return v;
  }
  int md = (l + r) >> 1;
  int ls = work(a, l, md);
  int rs = work(a, md + 1, r);
  if (ls > rs) swap(ls, rs);
  int &v = Mps[make_pair(ls, rs)];
  if (!v) v = ++cnt;
  return v;
}
int main() {
  scanf("%s%s", a + 1, b + 1);
  int len = strlen(a + 1);
  int A = work(a, 1, len);
  int B = work(b, 1, len);
  puts((A == B) ? "YES" : "NO");
  return 0;
}
