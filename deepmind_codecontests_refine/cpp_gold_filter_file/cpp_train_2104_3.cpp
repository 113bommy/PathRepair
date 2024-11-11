#include <bits/stdc++.h>
using namespace std;
const int offset = (1 << 20);
const int MAXN = 1000100;
struct node {
  int mini, maks;
  int val, prop;
};
const int inf = (1 << 30);
struct tournament {
  node p[offset * 2];
  tournament() {
    for (int i = (0); i < int(offset * 2); i++) {
      p[i].mini = 0;
      p[i].maks = 0;
      p[i].prop = 0;
      p[i].val = 0;
    }
  }
  node merge(node a, node b) {
    node ret;
    ret.prop = 0;
    ret.val = 0;
    ret.mini = min(a.mini, b.mini);
    ret.maks = max(a.maks, b.maks);
    return ret;
  }
  void send_prop(int cvor) {
    int x = p[cvor].prop;
    for (int i = (cvor * 2); i < int(cvor * 2 + 2); i++) {
      p[i].maks += x;
      p[i].mini += x;
      p[i].val += x;
      p[i].prop += x;
    }
    p[cvor].prop = 0;
  }
  void update(int cvor, int l, int r, int a, int b, int x) {
    if (l > b || r < a) return;
    if (l >= a && r <= b) {
      p[cvor].val += x;
      p[cvor].mini += x;
      p[cvor].maks += x;
      p[cvor].prop += x;
      return;
    }
    send_prop(cvor);
    int mid = (l + r) / 2;
    update(cvor * 2, l, mid, a, b, x);
    update(cvor * 2 + 1, mid + 1, r, a, b, x);
    p[cvor] = merge(p[cvor * 2], p[cvor * 2 + 1]);
  }
  node get() { return p[1]; }
};
tournament T;
char tmp[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int pt = 0;
  int sum = 0;
  for (int i = (0); i < int(n); i++) {
    if (s[i] == 'L') {
      pt--;
      pt = max(pt, 0);
    } else if (s[i] == 'R') {
      pt++;
    } else if (s[i] == '(') {
      int pov = 1;
      if (tmp[pt] == ')') pov++;
      if (tmp[pt] == '(') pov--;
      sum += pov;
      tmp[pt] = '(';
      T.update(1, 0, offset - 1, pt, MAXN, pov);
    } else if (s[i] == ')') {
      int pov = -1;
      if (tmp[pt] == ')') pov++;
      if (tmp[pt] == '(') pov--;
      sum += pov;
      tmp[pt] = ')';
      T.update(1, 0, offset - 1, pt, MAXN, pov);
    } else {
      int pov = 0;
      if (tmp[pt] == ')') pov++;
      if (tmp[pt] == '(') pov--;
      sum += pov;
      tmp[pt] = s[i];
      if (pov) T.update(1, 0, offset - 1, pt, MAXN, pov);
    }
    if (T.get().mini == 0 && !sum)
      printf("%d ", T.get().maks);
    else
      printf("-1 ");
  }
  puts("");
  return 0;
}
