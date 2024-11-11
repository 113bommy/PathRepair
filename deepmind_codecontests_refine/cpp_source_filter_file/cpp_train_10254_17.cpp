#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
char a[maxn], b[maxn];
int sa[26][maxn], sb[26][maxn];
int n;
void ins(int s[], int x, int t) {
  for (; x < maxn; x += (x & -x)) s[x] += t;
}
int get(int s[], int x) {
  int ret = 0;
  for (; x; x -= (x & -x)) ret += s[x];
  return ret;
}
int get(int s[], int l, int r) { return get(s, r) - get(s, l - 1); }
void gao(char a[], int s[26][maxn]) {
  for (int i = 1; i <= n; i++) {
    int c = a[i - 1] - 'a';
    ins(s[c], i, 1);
  }
}
bool same(int al, int ar, int bl, int br) {
  if ((ar - al + 1) % 2 == 1) {
    for (int i = al, j = bl; i <= ar; i++, j++)
      if (a[i] != b[j]) return false;
    return true;
  }
  for (int i = 0; i < 26; i++)
    if (get(sa[i], al, ar) != get(sb[i], bl, br)) return false;
  int am = (al + ar) / 2;
  int bm = (bl + br) / 2;
  return same(al, am, bl, bm) && same(am + 1, ar, bm + 1, br) ||
         same(al, am, bm + 1, br) && same(am + 1, ar, bl, bm);
}
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }
  cin >> a >> b;
  n = strlen(a);
  gao(a, sa);
  gao(b, sb);
  if (same(1, n, 1, n))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
