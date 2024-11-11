#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 256;
char op[MAXN], A[MAXN], B[MAXN];
char buff[MAXN], next[MAXN];
map<string, string> mp;
inline void getpq(const char s[], int &p, int &q) {
  int len, i, j, k;
  len = strlen(s);
  for (i = 0; s[i] == '&'; ++i)
    ;
  p = i;
  for (i = len - 1; s[i] == '*'; --i)
    ;
  q = len - i - 1;
}
inline void getout(const char s[]) {
  int i, j, k;
  int p(0);
  for (i = 0; s[i]; ++i) {
    if (s[i] == '&' || s[i] == '*') continue;
    buff[p++] = s[i];
  }
  buff[p] = '\0';
}
int main() {
  int i, j, k;
  int m, n;
  int len;
  int p, q;
  int ap, aq;
  int bp, bq;
  mp["void"] = "void";
  mp["errtype"] = "errtype";
  scanf("%d", &n);
  while (n--) {
    scanf("%s", op);
    if (op[4] == 'o') {
      scanf("%s", A);
      getout(A);
      string a(buff);
      if (!mp.count(a)) {
        puts("errtype");
      } else {
        string fa(mp[a]);
        if (fa == "errtype") {
          puts("errtype");
        } else {
          getout(fa.c_str());
          string b(buff);
          getpq(A, ap, aq);
          getpq(fa.c_str(), bp, bq);
          p = ap + bp, q = aq + bq;
          if (p <= q)
            for (i = p; i < q; ++i) b += "*";
          else
            b = "errtype";
          puts(b.c_str());
        }
      }
    } else {
      scanf("%s %s", A, B);
      getout(A);
      string a(buff);
      getpq(A, ap, aq);
      if (mp.count(a)) {
        getpq(mp[a].c_str(), bp, bq);
        getout(mp[a].c_str());
        string x(buff);
        p = ap + bp, q = aq + bq;
        if (x != "errtype") {
          if (p <= q) {
            for (i = p; i < q; ++i) x += '*';
          } else {
            x = "errtype";
          }
        }
        mp[string(B)] = x;
      } else {
        mp[string(B)] = "errtype";
      }
    }
  }
  return 0;
}
