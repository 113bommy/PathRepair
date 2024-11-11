#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int c;
  int num;
};
node dis[100005], dish[100005];
long long ans;
int n, m, kind, num;
int a[100005], c[100005], cheap[100005];
int cmp(node x, node y) { return x.c < y.c; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &dish[i].a);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &dish[i].c);
    dish[i].num = i;
  }
  for (int i = 1; i <= n; i++) {
    dis[i].a = dish[i].a;
    dis[i].c = dish[i].c;
  }
  sort(dish + 1, dish + 1 + n, cmp);
  for (int i = 1; i <= n; i++) cheap[i] = dish[i].num;
  int now = 1;
  for (int i = 1; i <= m; i++) {
    ans = 0;
    int left = num;
    scanf("%d%d", &kind, &num);
    if (now <= n) {
      if (dis[kind].a >= num) {
        ans += (long long)(num * dis[kind].c);
        dis[kind].a -= num;
        left = 0;
      } else {
        left = num - dis[kind].a;
        ans += (long long)(dis[kind].a * dis[kind].c);
        dis[kind].a = 0;
        while (left && now <= n) {
          if (dis[cheap[now]].a >= left) {
            ans += (long long)(dis[cheap[now]].c * left);
            dis[cheap[now]].a -= left;
            left = 0;
          } else {
            ans += (long long)(dis[cheap[now]].c * dis[cheap[now]].a);
            left -= dis[cheap[now]].a;
            dis[cheap[now]].a = 0;
            now++;
          }
        }
      }
    }
    if (left) ans = 0;
    cout << ans << endl;
  }
}
