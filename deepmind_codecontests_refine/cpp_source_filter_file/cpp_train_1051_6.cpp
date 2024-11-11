#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, st[N], top;
struct po {
  int x, y, c, id;
  bool operator!=(const po& k) { return x != k.x || y != k.y; }
} a[N];
long long cross(long long a, long long b, long long c, long long d) {
  return a * d - b * c;
}
void sol(po k1, po k2, po k3, vector<po> v) {
  if (k2.c == k3.c) swap(k1, k3);
  if (k1.c == k3.c) swap(k2, k3);
  if (cross((k1).x - (k3).x, (k1).y - (k3).y, (k2).x - (k3).x,
            (k2).y - (k3).y) < 0)
    swap(k1, k2);
  {
    vector<po> vv;
    for (const auto& x : v) {
      if (cross((k1).x - (k3).x, (k1).y - (k3).y, (x).x - (k3).x,
                (x).y - (k3).y) > 0 &&
          cross((x).x - (k3).x, (x).y - (k3).y, (k2).x - (k3).x,
                (k2).y - (k3).y) > 0 &&
          cross((k2).x - (k1).x, (k2).y - (k1).y, (x).x - (k1).x,
                (x).y - (k1).y) > 0)
        vv.push_back(x);
    }
    v = vv;
  }
  bool flg = 0;
  po cur;
  for (int i = (0); i <= (((int)(v).size()) - 1); ++i)
    if (v[i].c == k3.c) {
      flg = 1;
      cur = v[i];
    }
  if (flg) {
    printf("%d %d\n", cur.id, k3.id);
    sol(k1, k2, cur, v), sol(k1, k3, cur, v), sol(k2, k3, cur, v);
  } else {
    sort(v.begin(), v.end(), [&](po a, po b) {
      return cross((a).x - (k1).x, (a).y - (k1).y, (b).x - (k1).x,
                   (b).y - (k1).y) > 0;
    });
    for (int i = (0); i <= (((int)(v).size()) - 1); ++i)
      printf("%d %d\n", k1.id, v[i].id);
  }
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    exit(0);
  }
  vector<po> v;
  for (int i = (1); i <= (n); ++i)
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c), a[i].id = i - 1;
  {
    int pos =
        min_element(a + 1, a + 1 + n,
                    [&](po k1, po k2) {
                      return make_pair(k1.y, k1.x) < make_pair(k2.y, k2.x);
                    }) -
        a;
    swap(a[1], a[pos]);
    po bs = a[1];
    for (int i = (1); i <= (n); ++i) a[i].x -= bs.x, a[i].y -= bs.y;
    sort(a + 1, a + 1 + n,
         [&](po k1, po k2) { return cross(k1.x, k1.y, k2.x, k2.y) > 0; });
  }
  for (int i = (1); i <= (n); ++i) v.push_back(a[i]);
  {
    bool flg = 1;
    for (int i = (2); i <= (n); ++i) flg &= a[i].c == a[1].c;
    if (flg) {
      printf("%d\n", n - 1);
      for (int i = (2); i <= (n); ++i) {
        printf("%d %d\n", a[1].id, a[i].id);
      }
      return 0;
    }
  }
  {
    for (int i = (1); i <= (n); ++i) {
      while (top > 1 &&
             cross((a[i]).x - (a[st[top - 1]]).x, (a[i]).y - (a[st[top - 1]]).y,
                   (a[st[top]]).x - (a[st[top - 1]]).x,
                   (a[st[top]]).y - (a[st[top - 1]]).y) > 0)
        --top;
      st[++top] = i;
    }
    int tem = a[st[1]].c;
    int l = 1, r = top;
    while (l <= r && a[st[l]].c == tem) ++l;
    while (l <= r && a[st[r]].c == tem) --r;
    if (l > r) {
      printf("%d\n", n - 2);
      for (int i = (1); i <= (top - 1); ++i)
        printf("%d %d\n", a[st[i]].id, a[st[i + 1]].id);
      int pos = -1;
      for (int i = (1); i <= (n); ++i) {
        if (a[i].c != a[st[1]].c) {
          pos = i;
          break;
        }
      }
      for (int i = (1); i <= (top); ++i) {
        sol(a[st[i]], a[st[i % top + 1]], a[pos], v);
      }
    } else {
      for (int i = (l); i <= (r); ++i)
        if (a[st[i]].c != a[st[l]].c) {
          puts("Impossible");
          exit(0);
        }
      printf("%d\n", n - 2);
      for (int i = (1); i <= (top); ++i)
        if (a[st[i]].c == a[st[i % top + 1]].c)
          printf("%d %d\n", a[st[i]].id, a[st[i % top + 1]].id);
      for (int i = (l); i <= (r - 1); ++i) {
        sol(a[st[l - 1]], a[st[i]], a[st[i + 1]], v);
      }
      for (int i = (r + 1); i <= (top); ++i)
        sol(a[st[r]], a[st[i]], a[st[i % top + 1]], v);
      for (int i = (1); i <= (l - 2); ++i)
        sol(a[st[r]], a[st[i]], a[st[i % top + 1]], v);
    }
  }
  return 0;
}
