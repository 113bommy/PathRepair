#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[200100], rk[200100], sa[200100], height[200100], h[200100];
int has[200100], p1 = 31, sum[200100][30], dp[200100][30], flag2;
int pp[200100], f1, f2, lg[200100], len, len1, len2, lastr[200100],
    lastl[200100];
int cnt2, k, q;
char str[200100];
struct doge {
  int first, second, id;
} a[200100], b[200100];
struct node {
  int left, right, Min, lazy;
  node *ch[2];
} pool[12 * 200100], *root1, *rootr, *rootl;
void buildtree(node *p, int left, int right) {
  p->left = left;
  p->right = right;
  p->Min = 1000000000;
  p->lazy = 1000000000;
  if (left == right) return;
  int mid = (left + right) / 2;
  node *lson = &pool[++cnt2], *rson = &pool[++cnt2];
  p->ch[0] = lson;
  p->ch[1] = rson;
  buildtree(lson, left, mid);
  buildtree(rson, mid + 1, right);
}
void push(node *p) {
  if (p->lazy == 1000000000) return;
  if (p->ch[0]) p->ch[0]->lazy = min(p->ch[0]->lazy, p->lazy);
  if (p->ch[1]) p->ch[1]->lazy = min(p->ch[1]->lazy, p->lazy);
  p->Min = min(p->Min, p->lazy);
  p->lazy = 1000000000;
}
void change(node *p, int left, int right, int s) {
  if (p->left == left && p->right == right) {
    p->lazy = min(p->lazy, s);
    return;
  }
  push(p);
  if (p->ch[0]->right >= right)
    change(p->ch[0], left, right, s);
  else if (p->ch[1]->left <= left)
    change(p->ch[1], left, right, s);
  else {
    change(p->ch[0], left, p->ch[0]->right, s);
    change(p->ch[1], p->ch[1]->left, right, s);
  }
  if (p->ch[0]) push(p->ch[0]);
  if (p->ch[1]) push(p->ch[1]);
  p->Min = min(p->ch[0]->Min, p->ch[1]->Min);
}
int query(node *p, int left, int right) {
  push(p);
  if (p->left == left && p->right == right) return p->Min;
  if (p->ch[0]->right >= right)
    return query(p->ch[0], left, right);
  else if (p->ch[1]->left <= left)
    return query(p->ch[1], left, right);
  else
    return min(query(p->ch[0], left, p->ch[0]->right),
               query(p->ch[1], p->ch[1]->left, right));
}
int ha(int u, int v) { return has[v] - has[u - 1] * pp[v - u + 1]; }
bool checklcp(int u, int v, int mid) {
  if (mid == 0) return true;
  if (u - mid < 1 || v - mid < 1) return false;
  if (ha(u - mid, u - 1) == ha(v - mid, v - 1))
    return true;
  else
    return false;
}
bool checklcs(int u, int v, int mid) {
  if (mid == 0) return true;
  if (u + mid > n || v + mid > n) return false;
  if (ha(u + 1, u + mid) == ha(v + 1, v + mid))
    return true;
  else
    return false;
}
int lcp(int u, int v) {
  if (u == v) return n - u + 1;
  f1 = rk[u];
  f2 = rk[v];
  if (f1 > f2) swap(f1, f2);
  f1++;
  int cnt3 = lg[f2 - f1 + 1];
  return min(dp[f1][cnt3], dp[f2 - (1 << cnt3) + 1][cnt3]);
}
int ask(int u, int v) {
  int N = sqrt(n);
  for (int i = 1; i <= N && i <= v - u + 1; i++)
    if (lcp(u, v - i + 1) >= i) return i;
  int Mn = n + 1;
  for (int i = max(1, sa[u] - N + 1); i <= min(n, sa[u] + N - 1); i++) {
    if (sa[i] <= u || sa[i] > v) continue;
    if (lcp(u, sa[i]) >= v - sa[i] + 1) Mn = min(Mn, v - sa[i] + 1);
  }
  return Mn;
}
bool check0(int u, int v) {
  flag2 = 0;
  for (int i = 0; i <= 25; i++) {
    if (sum[v][i] - sum[u - 1][i] > 1) flag2 = 1;
  }
  if (flag2 == 0)
    return true;
  else
    return false;
}
bool check1(int u, int v) {
  len = v - u + 1;
  len2 = v - u + 1;
  for (int i = 2; i * i <= len; i++) {
    if (len % i == 0) {
      while (len % i == 0) len /= i;
      if (lcp(u, u + len2 / i) >= len2 - len2 / i) return true;
    }
  }
  if (len > 1) {
    if (lcp(u, u + len2 / len) >= len2 - len2 / len) return true;
  }
  return false;
}
bool check2(int u, int v) {
  if (lastr[u] <= v) return true;
  if (lastl[v] >= u) return true;
  if (ask(u, v) * 2 <= v - u + 1) return true;
  return false;
}
bool check3(int u, int v) {
  int w = str[u] - 'a';
  if (sum[v][w] - sum[u][w] >= 1) return true;
  w = str[v] - 'a';
  if (sum[v - 1][w] - sum[u - 1][w] >= 1) return true;
  w = query(root1, u, v);
  if (w <= v)
    return true;
  else
    return false;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  int u, v, Lcp, Lcs;
  rootr = &pool[++cnt2];
  rootl = &pool[++cnt2];
  root1 = &pool[++cnt2];
  buildtree(rootr, 1, n);
  buildtree(rootl, 1, n);
  buildtree(root1, 1, n);
  lg[0] = -1;
  for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 25; j++) {
      sum[i][j] = sum[i - 1][j];
      if (str[i] - 'a' == j) sum[i][j]++;
    }
  for (int i = 1; i <= n; i++) cnt[str[i]]++;
  for (int i = 1; i <= 128; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) rk[i] = cnt[str[i]];
  for (int Len = 1; Len <= n; Len *= 2) {
    for (int i = 1; i <= n; i++) {
      a[i].id = i;
      a[i].first = rk[i];
      a[i].second = rk[i + Len];
    }
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i].second]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) b[cnt[a[i].second]--] = a[i];
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[b[i].first]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) a[cnt[b[i].first]--] = b[i];
    rk[a[1].id] = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i].first == a[i - 1].first && a[i].second == a[i - 1].second)
        rk[a[i].id] = rk[a[i - 1].id];
      else
        rk[a[i].id] = rk[a[i - 1].id] + 1;
    }
  }
  for (int i = 1; i <= n; i++) sa[rk[i]] = i;
  for (int i = 1; i <= n; i++) {
    if (k > 0) k--;
    f1 = sa[rk[i]];
    f2 = sa[rk[i] - 1];
    while (str[f1 + k] == str[f2 + k]) k++;
    height[rk[i]] = k;
  }
  for (int i = 1; i <= n; i++) dp[i][0] = height[i];
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
  pp[0] = 1;
  for (int i = 1; i <= n; i++)
    has[i] = has[i - 1] * p1 + str[i], pp[i] = pp[i - 1] * p1;
  int left, right, as, mid;
  for (int Len = 1; Len <= n; Len++) {
    for (int i = 1; i + Len <= n; i += Len) {
      u = i;
      v = i + Len;
      if (str[u] != str[v]) continue;
      left = 0;
      right = Len - 1;
      Lcp = Lcs = 0;
      while (left <= right) {
        mid = (left + right) / 2;
        if (checklcp(u, v, mid) == true)
          Lcp = mid, left = mid + 1;
        else
          right = mid - 1;
      }
      left = 0;
      right = Len - 1;
      while (left <= right) {
        mid = (left + right) / 2;
        if (checklcs(u, v, mid) == true)
          Lcs = mid, left = mid + 1;
        else
          right = mid - 1;
      }
      if (Lcs + Lcp < Len - 1) continue;
      len1 = Lcs + Lcp - (Len - 1) + 1;
      change(rootr, u - Lcp, u - Lcp + len1 - 1, Len);
      change(rootl, v + Lcs - len1 + 1, v + Lcs, Len);
    }
  }
  for (int i = 1; i <= n; i++) {
    lastr[i] = i + query(rootr, i, i) * 2 - 1;
    lastl[i] = i - query(rootl, i, i) * 2 + 1;
    change(root1, i, i, lastr[i]);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &u, &v);
    if (check0(u, v) == true)
      printf("-1\n");
    else if (check1(u, v) == true)
      printf("1\n");
    else if (check2(u, v) == true)
      printf("2\n");
    else if (check3(u, v) == true)
      printf("3\n");
    else
      printf("4\n");
  }
  return 0;
}
