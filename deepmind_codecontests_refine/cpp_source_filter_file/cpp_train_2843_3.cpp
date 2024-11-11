#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
long long int siz, last;
struct automata {
  long long int len, link, next[26];
} st[2][100000 * 2 + 5];
long long int o[2][100000 * 2 + 5];
void inser(char c, long long int f) {
  long long int now = ++siz;
  st[f][now].len = st[f][last].len + 1;
  long long int p, q, cl;
  for (p = last; p != -1 && !st[f][p].next[c]; p = st[f][p].link)
    st[f][p].next[c] = now;
  if (p == -1)
    st[f][now].link = 0;
  else {
    q = st[f][p].next[c];
    if (st[f][p].len + 1 == st[f][q].len)
      st[f][now].link = q;
    else {
      cl = ++siz, st[f][cl].len = st[f][p].len + 1;
      st[f][cl].link = st[f][q].link;
      memcpy(st[f][cl].next, st[f][q].next, sizeof(st[f][cl].next));
      for (; p != -1 && st[f][p].next[c] == q; p = st[f][p].link)
        st[f][p].next[c] = cl;
      st[f][now].link = st[f][q].link = cl;
      o[f][cl] = o[f][q];
    }
  }
  o[f][now] = st[f][now].len - 1;
  last = now;
}
int main() {
  long long int i, j;
  string t;
  cin >> t;
  st[0][0].link = -1;
  for (i = 0; i < t.size(); i++) inser(t[i] - 'A', 0);
  siz = 0, last = 0;
  st[1][0].link = -1;
  for (i = t.size() - 1; i >= 0; i--) inser(t[i] - 'A', 1);
  string t1;
  long long int m;
  cin >> m;
  long long int a[1005];
  long long int cn = 0;
  while (m--) {
    cin >> t1;
    long long int now = 0;
    memset(a, 0, sizeof(a));
    for (i = 0; i < t1.size(); i++) {
      long long int p = st[0][now].next[t1[i] - 'A'];
      if (p == 0) break;
      a[i] = o[0][p];
      now = p;
    }
    now = 0;
    for (i = t1.size() - 1; i >= 1; i--) {
      long long int p = st[1][now].next[t1[i] - 'A'];
      if (p == 0) break;
      long long int p1 = t.size() - o[1][p] - 1;
      if (a[i - 1] != 0 && p1 > a[i - 1]) {
        cn++;
        break;
      }
      now = p;
    }
  }
  cout << cn << endl;
}
