#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pi;

#define fi first
#define se second

ll read() {
  ll res = 0, w = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - '0', c = getchar();
  return res * w;
}

const int N = 2e5 + 10;

int st[N], p[N], a[N], nxt[N], las[N], x[N], n, pos, top;
ll k;

int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    nxt[las[a[i]]] = i;
    las[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    nxt[las[a[i]]] = i;
    las[a[i]] = i;
  }
  for (int i = 1; i < n; i++) x[i] = i + 1;
  x[n] = 1;
  st[++top] = 1, p[top] = 1, pos = 1;
  do {
    ++top, p[top] = p[top - 1] + (nxt[pos] <= pos) + (nxt[pos] == n);
    st[top] = pos = x[nxt[pos]];
  } while (st[top] != st[1]);
  k -= (k - 1) / (p[top] - 1) * (p[top] - 1);
  R int j = 1;
  while (j <= top - 1 && p[j + 1] <= k) ++j;
  for (int i = st[j]; i <= n; ++i) {
    if (nxt[i] > i)
      i = nxt[i];
    else
      printf("%d ", a[i]);
  }
  return 0;
}