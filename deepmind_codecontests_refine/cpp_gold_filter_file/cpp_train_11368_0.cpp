#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
char s[1111];
int n, i, j, k, l, p;
bool pd[1111];
int f[1111], sz[1111], z[111], li[1111], d[1111], st[1111], w[1111];
int get(int i) { return f[i] == i ? i : f[i] = get(f[i]); }
void merge(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    f[x] = y;
    sz[y] += sz[x];
  }
}
multiset<pair<int, int> > S;
multiset<pair<int, int> >::iterator it;
bool cmp(int a, int b) { return li[a] > li[b]; }
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (i = 1; i <= n; i++) z[s[i] - 'a']++;
  for (i = 0; i <= 25; i++) S.insert(make_pair(z[i], i));
  for (i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  for (i = 2; i <= n; i++)
    if (!pd[i])
      for (j = 2; j <= n / i; j++) pd[i * j] = 1, merge(i * j, i);
  for (i = 1; i <= n; i++)
    if (get(i) == i) li[++li[0]] = sz[i], w[li[0]] = i, st[++st[0]] = li[0];
  sort(st + 1, st + 1 + li[0]);
  int pos;
  for (pos = 1; pos <= li[0]; pos++) {
    i = st[pos];
    it = S.lower_bound(make_pair(li[i], 0));
    if (it == S.end()) return puts("NO"), 0;
    int p = it->first, c = it->second;
    S.erase(it);
    S.insert(make_pair(p - li[i], c));
    d[w[i]] = c;
  }
  printf("YES\n");
  for (i = 1; i <= n; i++) printf("%c", 'a' + d[get(i)]);
  return 0;
}
