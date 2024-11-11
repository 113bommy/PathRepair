#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 20;
char s[MAX];
struct node {
  char val;
  int gs, base;
  node(char a = 0, int b = 0, int c = 0) : val(a), gs(b), base(c) {}
};
node ns[MAX];
int nscnt;
int main() {
  scanf("%s", s);
  int slen = strlen(s);
  int pos = slen - 1;
  const int diff = slen - 1;
  nscnt = 0;
  while (pos >= 0) {
    char cur = s[pos];
    int nxt = pos - 1;
    while (nxt >= 0 && s[nxt] == cur) nxt--;
    ns[nscnt++] = {cur, pos - nxt, diff - pos};
    pos = nxt;
  }
  pos = 0;
  vector<string> sl;
  char tmp[300];
  while (pos < nscnt) {
    if (ns[pos].val == '0')
      pos++;
    else if (ns[pos].gs == 1) {
      sprintf(tmp, "+2^%d\n", ns[pos].base);
      sl.push_back(string(tmp));
      pos++;
    } else {
      sprintf(tmp, "-2^%d\n", ns[pos].base);
      sl.push_back(string(tmp));
      int nxt = pos + 1;
      while (nxt >= 0 && ns[nxt].gs == 1) {
        sprintf(tmp, "-2^%d\n", ns[nxt].base);
        sl.push_back(string(tmp));
        nxt += 2;
      }
      if (nxt >= 0)
        sprintf(tmp, "+2^%d\n", ns[nxt].base);
      else
        sprintf(tmp, "+2^%d\n", slen);
      sl.push_back(string(tmp));
      pos = nxt;
    }
  }
  printf("%d\n", sl.size());
  for (int i = 0; i < sl.size(); i++) cout << sl[i];
  return 0;
}
