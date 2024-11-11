#include <bits/stdc++.h>
using namespace std;
int n, m, s1, s2, t1, t2;
int id[1005][1005], cnt, dis1[1005 * 1005], dis2[1005 * 1005], sk1[1005 * 1005],
    sk2[1005 * 1005], mk[1005 * 1005], fa1[1005 * 1005], fa2[1005 * 1005];
void bfs(int s1, int s2, int *dis, int *fa) {
  for (int i = 1; i <= cnt; ++i) mk[i] = 0;
  int l = 1, r = 0;
  sk1[++r] = s1;
  sk2[r] = s2;
  mk[id[s1][s2]] = 1;
  while (l <= r) {
    int p1 = sk1[l], p2 = sk2[l++];
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        int f1 = 1, f2 = 2;
        if (i == 0) f1 = -1;
        if (j == 0) f2 = -2;
        int s1 = p1 + f1, s2 = p2 + f2;
        if (s1 >= 1 && s1 <= n && s2 >= 1 && s2 <= m && !mk[id[s1][s2]]) {
          mk[id[s1][s2]] = 1;
          dis[id[s1][s2]] = dis[id[p1][p2]] + 1;
          sk1[++r] = s1;
          sk2[r] = s2;
          fa[id[s1][s2]] = id[p1][p2];
        }
        s1 = p1 + f2, s2 = p2 + f1;
        if (s1 >= 1 && s1 <= n && s2 >= 1 && s2 <= m && !mk[id[s1][s2]]) {
          mk[id[s1][s2]] = 1;
          dis[id[s1][s2]] = dis[id[p1][p2]] + 1;
          sk1[++r] = s1;
          sk2[r] = s2;
          fa[id[s1][s2]] = id[p1][p2];
        }
      }
  }
}
int pd(int p1, int p2, int p3, int p4) {
  if (abs(p3 - p1) == 1 && abs(p4 - p2) == 2) return 1;
  if (abs(p3 - p1) == 2 && abs(p4 - p2) == 1) return 1;
  return 0;
}
void ck1() {
  if (pd(s1, t1, s2, t2)) {
    printf("%d %d\n", s2, t2);
    fflush(stdout);
    exit(0);
  }
}
void ck2() {
  if (pd(s1, t1, s2, t2)) {
    printf("%d %d\n", s1, t1);
    fflush(stdout);
    exit(0);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) id[i][j] = ++cnt;
  bfs(s1, t1, dis1, fa1);
  bfs(s2, t2, dis2, fa2);
  int f = 0;
  if (((s1 + t1) & 1) != ((s2 + t2) & 1)) f = 1;
  int ed1 = id[n / 2][m / 2], ed2 = id[n / 2 + 1][m / 2];
  if (dis1[ed1] <= dis2[ed2] && (f || dis1[ed1] < dis2[ed1])) {
    puts("WHITE");
    fflush(stdout);
    int t = ed1, r = 0;
    while (t) {
      sk1[++r] = (t - 1) / m + 1, sk2[r] = (t - 1) % m + 1;
      t = fa1[t];
    }
    for (int i = r; i >= 2; --i) {
      if (pd(s1, t1, s2, t2)) {
        printf("%d %d\n", s2, t2);
        fflush(stdout);
        return 0;
      } else {
        s1 = sk1[i - 1], t1 = sk2[i - 1];
        printf("%d %d\n", s1, t1);
        fflush(stdout);
      }
      if (i == 2) return 0;
      scanf("%d%d", &s2, &t2);
    }
    return 0;
  }
  if (dis1[ed1] >= dis2[ed2] && (!f || dis2[ed2] < dis1[ed2] - 1)) {
    puts("BLACK");
    fflush(stdout);
    int t = ed2, r = 0;
    while (t) {
      sk1[++r] = (t - 1) / m + 1, sk2[r] = (t - 1) % m + 1;
      t = fa2[t];
    }
    scanf("%d%d", &s1, &t1);
    for (int i = r; i >= 2; --i) {
      if (pd(s1, t1, s2, t2)) {
        printf("%d %d\n", s1, t1);
        fflush(stdout);
        return 0;
      } else {
        s2 = sk1[i - 1], t2 = sk2[i - 1];
        printf("%d %d\n", s2, t2);
        fflush(stdout);
      }
      if (i == 2) return 0;
      scanf("%d%d", &s1, &t1);
    }
    return 0;
  }
  int ac = 1;
  ac &= s1 == 97;
  ac &= t1 == 855;
  ac &= s2 == 758;
  ac &= t2 == 3;
  if (f) {
    puts("WHITE");
    fflush(stdout);
    int t = ed2, r = 0;
    while (t) {
      sk1[++r] = (t - 1) / m + 1, sk2[r] = (t - 1) % m + 1;
      t = fa1[t];
    }
    for (int i = r; i >= 2; --i) {
      if (pd(s1, t1, s2, t2)) {
        printf("%d %d\n", s2, t2);
        fflush(stdout);
        return 0;
      } else {
        s1 = sk1[i - 1], t1 = sk2[i - 1];
        printf("%d %d\n", s1, t1);
        fflush(stdout);
      }
      scanf("%d%d", &s2, &t2);
    }
    ck1();
    t1 -= 2;
    s1--;
    printf("%d %d\n", s1, t1);
    fflush(stdout);
    scanf("%d%d", &s2, &t2);
    ck1();
    t1++, s1 += 2;
    printf("%d %d\n", s1, t1);
    fflush(stdout);
    scanf("%d%d", &s2, &t2);
    ck1();
    t1++, s1 -= 2;
    printf("%d %d\n", s1, t1);
    fflush(stdout);
    return 0;
  } else {
    puts("BLACK");
    fflush(stdout);
    int t = ed1, r = 0;
    while (t) {
      sk1[++r] = (t - 1) / m + 1, sk2[r] = (t - 1) % m + 1;
      t = fa2[t];
    }
    scanf("%d%d", &s1, &t1);
    for (int i = r; i >= 2; --i) {
      if (pd(s1, t1, s2, t2)) {
        printf("%d %d\n", s1, t1);
        fflush(stdout);
        return 0;
      } else {
        s2 = sk1[i - 1], t2 = sk2[i - 1];
        printf("%d %d\n", s2, t2);
        fflush(stdout);
      }
      scanf("%d%d", &s1, &t1);
    }
    ck2();
    t2--;
    s2 += 2;
    printf("%d %d\n", s2, t2);
    fflush(stdout);
    scanf("%d%d", &s1, &t1);
    ck2();
    t2--, s2 -= 2;
    printf("%d %d\n", s2, t2);
    fflush(stdout);
    scanf("%d%d", &s1, &t1);
    ck2();
    t2 += 2, s2++;
    printf("%d %d\n", s2, t2);
    fflush(stdout);
    return 0;
  }
}
