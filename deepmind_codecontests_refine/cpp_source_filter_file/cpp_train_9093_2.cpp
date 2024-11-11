#include <bits/stdc++.h>
using namespace std;
int n, h;
int a[200008];
struct arr {
  int i, v;
  bool operator<(const arr &t) const { return v < t.v; }
} p[200008];
int ans[200008], ans1, tmp[200008];
struct Tprogram {
  void Open() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
  }
  void Close() {
    fclose(stdin);
    fclose(stdout);
  }
  void Init() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      p[i].v = a[i];
      p[i].i = i;
    }
    sort(a + 1, a + n + 1);
    sort(p + 1, p + n + 1);
  }
  void Work() {
    int t = -1, ans1 = 1e9;
    for (int i = n - 1; i >= 1; i--) {
      int maxx = (a[n] + a[n - 1] > a[n] + a[i] + h ? a[n] + a[n - 1]
                                                    : a[n] + a[i] + h);
      if (i >= 2) {
        int minn = ((a[1] + a[2] + h < a[2] + a[3] ? a[1] + a[2] + h
                                                   : a[2] + a[3]) < a[1] + a[i]
                        ? (a[1] + a[2] + h < a[2] + a[3] ? a[1] + a[2] + h
                                                         : a[2] + a[3])
                        : a[1] + a[i]);
        if (maxx - minn < ans1) {
          ans1 = maxx - minn;
          t = i;
        }
      }
    }
    if ((a[n] + a[1] + h > a[n] + a[n - 1] ? a[n] + a[1] + h
                                           : a[n] + a[n - 1]) -
            (a[2] + a[3] < (a[1] + a[2] + h) ? a[2] + a[3]
                                             : (a[1] + a[2] + h)) <
        ans1) {
      ans1 =
          (a[n] + a[1] + h > a[n] + a[n - 1] ? a[n] + a[1] + h
                                             : a[n] + a[n - 1]) -
          (a[2] + a[3] < (a[1] + a[2] + h) ? a[2] + a[3] : (a[1] + a[2] + h));
      t = 1;
    }
    if (a[n] + a[n - 1] - a[1] - a[2] < ans1) {
      ans1 = a[n] + a[n - 1] - a[1] - a[2];
      t = 0;
    }
    printf("%d\n", ans1);
    if (t == 0) {
      for (int i = 1; i <= n; i++) ans[i] = 1;
    } else if (t == 1) {
      ans[p[1].i] = 1;
      for (int i = 2; i <= n; i++) ans[p[i].i] = 2;
    } else {
      ans[p[1].i] = 1;
      ans[p[t].i] = 1;
      for (int i = 2; i <= n; i++)
        if (i != t) ans[p[i].i] = 2;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
} program;
void Dfs(int d) {
  if (d > n) {
    int maxx = -1e9, minn = 1e9;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (ans[i] != ans[j])
          maxx = (a[i] + a[j] + h > maxx ? a[i] + a[j] + h : maxx),
          minn = (a[i] + a[j] + h < minn ? a[i] + a[j] + h : minn);
        else
          maxx = (a[i] + a[j] > maxx ? a[i] + a[j] : maxx),
          minn = (a[i] + a[j] < minn ? a[i] + a[j] : minn);
    if (maxx - minn < ans1) {
      ans1 = maxx - minn;
      for (int i = 1; i <= n; i++) tmp[i] = ans[i];
    }
    return;
  }
  ans[d] = 1;
  Dfs(d + 1);
  ans[d] = 2;
  Dfs(d + 1);
}
void Work() {
  ans1 = 1e9;
  Dfs(1);
  printf("%d\n", ans1);
  for (int i = 1; i <= n; i++) printf("%d ", tmp[i]);
  printf("\n");
}
int main() {
  program.Init();
  if (n > 10)
    program.Work();
  else
    Work();
  return 0;
}
