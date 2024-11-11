#include <bits/stdc++.h>
using namespace std;
const int N = 201000;
struct Address {
  string s;
  int dig, ty;
  void Input(int *a, int num, int wob) {
    s = "";
    for (int i = 0; i < 4; i++)
      for (int j = 7; ~j; j--) s += char((a[i] >> j & 1) + '0');
    dig = num;
    ty = wob;
  }
  void Output(void) {
    static int a[4];
    for (int i = 0; i < 4; i++) {
      a[i] = 0;
      for (int j = 0; j < 8; j++) a[i] |= (s[i * 8 + j] - 48) * (1 << (7 - j));
      printf("%d", a[i]);
      putchar(i == 3 ? '/' : '.');
    }
    printf("%d\n", dig);
  }
  bool operator<(const Address &rhs) const { return dig < rhs.dig; }
} info[N];
Address Trans(long long x, int y) {
  static string s;
  s = "";
  for (int i = 31; ~i; i--) s += char(48 + (x >> i & 1));
  return {s, y, 0};
}
vector<Address> Ans;
int tot, n;
struct Node {
  int ch[2];
  int ty, stat, oo;
  Node(void) { ty = -1; }
} T[N * 32];
bool Insert(Address info) {
  int p = 0;
  if (~T[p].ty && T[p].ty != info.ty) return 0;
  for (int i = 0; i < info.dig; i++) {
    int idx = info.s[i] - 48;
    if (!T[p].ch[idx]) T[p].ch[idx] = ++tot;
    p = T[p].ch[idx];
    if (~T[p].ty && T[p].ty != info.ty) return 0;
  }
  T[p].ty = info.ty;
  return 1;
}
int Solve(int p, int dep, long long stat) {
  int v[2];
  int now = T[p].ty;
  for (int i = 0; i < 2; i++) {
    v[i] = T[p].ch[i]
               ? Solve(T[p].ch[i], dep + 1, stat | (i * (1LL << (31 - dep))))
               : -1;
  }
  if (now == 1 || v[0] + v[1] == 2) T[p].stat = stat, T[p].oo = dep;
  if (now >= v[0] && now >= v[1]) return now;
  assert(!~now);
  if (~v[0] && ~v[1] && v[0] != v[1]) {
    int son = T[p].ch[v[1]];
    Ans.push_back(Trans(T[son].stat, T[son].oo));
    return 0;
  }
  if (now != 1 && v[0] + v[1] != 2 && max(v[0], v[1]) == 1)
    T[p].stat = T[T[p].ch[v[1] == 1]].stat, T[p].oo = T[T[p].ch[v[1] == 1]].oo;
  return max(v[0], v[1]);
}
char s[99];
int main(void) {
  scanf("%d", &n);
  for (int i = 1, l, wob, dig; i <= n; i++) {
    scanf("%s", s);
    l = strlen(s);
    wob = s[0] == '-';
    static int a[4];
    int k = 1;
    for (int j = 0; j < 4; j++) {
      a[j] = 0;
      while (isdigit(s[k])) a[j] = a[j] * 10 + s[k++] - 48;
      while (k < l && !isdigit(s[k])) k++;
    }
    dig = (k == l) * 32;
    while (k < l && isdigit(s[k])) dig = dig * 10 + s[k++] - 48;
    info[i].Input(a, dig, wob);
  }
  sort(info + 1, info + n + 1);
  for (int i = 1; i <= n; i++)
    if (!Insert(info[i])) return puts("-1"), 0;
  if (Solve(0, 0, 0)) Ans.push_back(Trans(T[0].stat, T[0].oo));
  cout << Ans.size() << endl;
  for (Address v : Ans) v.Output();
  return 0;
}
