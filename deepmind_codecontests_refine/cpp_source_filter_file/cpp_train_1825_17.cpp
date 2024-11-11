#include <bits/stdc++.h>
using namespace std;
inline void splay(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
int n, m;
long long lena[200010], cnt;
long long lenb[200010];
char ca[200010], cb[200010];
int fail[200010];
bool comp(int i, int j) {
  if (lena[i] == lenb[j] && ca[i] == cb[j])
    return true;
  else
    return false;
}
bool check(int i, int j) {
  if (lenb[i] == lenb[j] && cb[i] == cb[j])
    return true;
  else
    return false;
}
int main() {
  splay(n), splay(m);
  for (int i = 1; i <= n; i++) {
    int l;
    char x;
    scanf("%d-%c", &l, &x);
    if (x == ca[cnt])
      lena[cnt] += (long long)l;
    else
      ++cnt, lena[cnt] = l, ca[cnt] = x;
  }
  n = cnt;
  cnt = 0;
  for (int i = 1; i <= m; i++) {
    int l;
    char x;
    scanf("%d-%c", &l, &x);
    if (x == cb[cnt])
      lenb[cnt] += (long long)l;
    else
      ++cnt, lenb[cnt] = l, cb[cnt] = x;
  }
  m = cnt;
  cnt = 0;
  long long ans = 0;
  if (m == 1) {
    for (int i = 1; i <= n; i++) {
      if (ca[i] == cb[1] && lena[i] >= lenb[1]) {
        ans += (long long)lena[i] - lenb[1] + 1;
      }
    }
    cout << ans << endl;
    return 0;
  } else if (m == 2) {
    for (int i = 1; i < n; i++) {
      if (ca[i] == cb[1] && ca[i + 1] == cb[2] && lena[i] >= lenb[1] &&
          lena[i + 1] >= lenb[2]) {
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
  } else {
    int lenl = lenb[1], cl = cb[1];
    int lenr = lenb[m], cr = cb[m];
    for (int i = 1; i <= m - 2; i++) cb[i] = cb[i + 1], lenb[i] = lenb[i + 1];
    m -= 2;
    for (int i = 2, j = 0; i <= m; i++) {
      while (j && !check(j + 1, i)) j = fail[j];
      if (check(j + 1, i)) j++;
      fail[j] = i;
    }
    for (int i = 1, j = 0; i <= n; i++) {
      while (j && !comp(i, j + 1)) j = fail[j];
      if (comp(i, j + 1)) j++;
      if (j == m) {
        j = fail[j];
        if (lena[i - m] >= lenl && ca[i - m] == cl && lena[i + 1] >= lenr &&
            ca[i + 1] == cr)
          ans++;
      }
    }
    cout << ans << endl;
  }
}
