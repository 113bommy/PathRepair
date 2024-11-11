#include <bits/stdc++.h>
using namespace std;
int n, sx, sy, tx, ty;
struct node {
  int x, y, rx, ry;
  double l, r;
} mice[100005];
bool cmp(node a, node b) { return a.l < b.l; }
bool checkcorner() {
  for (int i = 1; i <= n; i++) {
    int tmp1 = (sx - mice[i].x) * mice[i].ry - (sy - mice[i].y) * mice[i].rx;
    int tmp2 = (tx - mice[i].x) * mice[i].ry - (ty - mice[i].y) * mice[i].rx;
    int tmp3 = (sx - mice[i].x) * mice[i].ry - (ty - mice[i].y) * mice[i].rx;
    int tmp4 = (tx - mice[i].x) * mice[i].ry - (sy - mice[i].y) * mice[i].rx;
    if (!tmp1 || !tmp2 || !tmp4 || !tmp3) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d%d", &mice[i].x, &mice[i].y, &mice[i].rx, &mice[i].ry);
  for (int i = 1; i <= n; i++) {
    if (mice[i].rx == 0 && mice[i].ry == 0) {
      if (mice[i].x > sx && mice[i].x < tx && mice[i].y > sy && mice[i].y < ty)
        mice[i].l = 0, mice[i].r = 1000000000;
      else {
        printf("-1\n");
        return 0;
      }
    } else if (mice[i].rx == 0 && mice[i].ry) {
      if (mice[i].x <= sx || mice[i].x >= tx) {
        printf("-1\n");
        return 0;
      }
      if (mice[i].ry > 0) {
        if (mice[i].y >= ty) {
          printf("-1\n");
          return 0;
        }
        mice[i].l = max(0.0, (double)(sy - mice[i].y) / mice[i].ry);
        mice[i].r = (double)(ty - mice[i].y) / mice[i].ry;
      } else {
        if (mice[i].y <= sy) {
          printf("-1\n");
          return 0;
        }
        mice[i].l = max(0.0, (double)(mice[i].y - ty) / -mice[i].ry);
        mice[i].r = (double)(mice[i].y - sy) / -mice[i].ry;
      }
    } else if (mice[i].ry == 0 && mice[i].rx) {
      if (mice[i].y <= sy || mice[i].y >= ty) {
        printf("-1\n");
        return 0;
      }
      if (mice[i].rx > 0) {
        if (mice[i].x >= tx) {
          printf("-1\n");
          return 0;
        }
        mice[i].l = max(0.0, (double)(sx - mice[i].x) / mice[i].rx);
        mice[i].r = (double)(tx - mice[i].x) / mice[i].rx;
      } else {
        if (mice[i].x <= sx) {
          printf("-1\n");
          return 0;
        }
        mice[i].l = max(0.0, (double)(mice[i].x - tx) / -mice[i].rx);
        mice[i].r = (double)(mice[i].x - sx) / -mice[i].rx;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    double t1, t2, t3, t4;
    if (mice[i].rx == 0 || mice[i].ry == 0) continue;
    if (mice[i].rx > 0) {
      if (mice[i].x >= tx) {
        printf("-1\n");
        return 0;
      }
      t1 = max(0.0, (double)(sx - mice[i].x) / mice[i].rx);
      t2 = (double)(tx - mice[i].x) / mice[i].rx;
    } else if (mice[i].rx < 0) {
      if (mice[i].x <= sx) {
        printf("-1\n");
        return 0;
      }
      t1 = max(0.0, (double)(mice[i].x - tx) / -mice[i].rx);
      t2 = (double)(mice[i].x - sx) / -mice[i].rx;
    }
    if (mice[i].ry > 0) {
      if (mice[i].y >= ty) {
        printf("-1\n");
        return 0;
      }
      t3 = max(0.0, (double)(sy - mice[i].y) / mice[i].ry);
      t4 = (double)(ty - mice[i].y) / mice[i].ry;
    } else if (mice[i].ry < 0) {
      if (mice[i].y <= sy) {
        printf("-1\n");
        return 0;
      }
      t3 = max(0.0, (double)(mice[i].y - ty) / -mice[i].ry);
      t4 = (double)(mice[i].y - sy) / -mice[i].ry;
    }
    if (t1 > t2 || t3 > t4) {
      printf("-1\n");
      return 0;
    }
    mice[i].l = max(t1, t3);
    mice[i].r = min(t2, t4);
  }
  for (int i = 1; i <= n; i++)
    if (mice[i].l == mice[i].r) {
      printf("-1\n");
      return 0;
    }
  sort(mice + 1, mice + 1 + n, cmp);
  double lastr = mice[1].r, ans = mice[1].l;
  for (int i = 2; i <= n; i++) {
    if (mice[i].l >= lastr) {
      printf("-1\n");
      return 0;
    }
    lastr = min(lastr, mice[i].r);
    ans = mice[i].l;
  }
  printf("%.7lf\n", ans);
  return 0;
}
