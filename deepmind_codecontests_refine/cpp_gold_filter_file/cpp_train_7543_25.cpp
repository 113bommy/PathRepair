#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int oo[100005], ii[100005];
int ffail = -1, lfail = -1;
bool needmid;
int COUNT[100005];
bool canpalin() {
  for (int i = (0); i < (n); i++) COUNT[a[i]]++;
  int nodd = 0;
  for (int i = (0); i < (100005); i++) {
    if (COUNT[i] % 2) nodd++;
  }
  return nodd <= 1;
}
bool ispalin() {
  for (int i = (0); i < (n); i++)
    if (a[i] != a[n - i - 1]) return false;
  return true;
}
int s, e;
int nondom;
void modin(int x, int v) {
  if (ii[x] < oo[x]) nondom--;
  ii[x] += v;
  if (ii[x] < oo[x]) nondom++;
}
void modout(int x, int v) {
  if (ii[x] < oo[x]) nondom--;
  oo[x] += v;
  if (ii[x] < oo[x]) nondom++;
}
bool in(int i) { return s <= i && i < e; }
bool good() {
  if (!in(ffail) || !in(lfail)) {
    int FFAIL = n - 1 - ffail;
    int LFAIL = n - 1 - lfail;
    if (!in(FFAIL) || !in(LFAIL)) {
      return false;
    }
  }
  if (needmid && !in(n / 2)) return false;
  if (nondom) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  if (!canpalin()) {
    printf("0\n");
    return 0;
  }
  if (ispalin()) {
    cout << (n * 1ll * (n + 1)) / 2 << "\n";
    return 0;
  }
  for (int i = (0); i < (n / 2); i++) {
    if (a[i] != a[n - i - 1]) {
      if (ffail == -1) ffail = i;
      lfail = i;
    }
  }
  needmid = (n & 1) && (COUNT[a[n / 2]] % 2 == 0);
  long long res = 0;
  e = 0;
  for (s = 0; s < n; s++) {
    while (e == s || !good()) {
      if (e == n) {
        e = n + 1;
        s = n + 10;
        break;
      }
      int o = n - e - 1;
      if (o == e) {
        modin(a[e], 1);
      } else if (in(o)) {
        modin(a[e], 1);
        modout(a[e], -1);
      } else {
        modout(a[o], 1);
        modin(a[e], 1);
      }
      e++;
    }
    if (e == n + 1) break;
    res += n + 1 - e;
    int o = n - s - 1;
    if (o == s)
      modin(a[s], -1);
    else if (in(o)) {
      modin(a[s], -1);
      modout(a[s], 1);
    } else {
      modin(a[s], -1);
      modout(a[o], -1);
    }
  }
  cout << res << "\n";
}
