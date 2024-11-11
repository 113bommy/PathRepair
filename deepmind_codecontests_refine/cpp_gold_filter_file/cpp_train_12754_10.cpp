#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 100;
int n;
int a[N];
int m = 0;
pair<int, int> b[N];
int ans[N];
bool used[N];
void Fail() {
  printf("-1\n");
  exit(0);
}
int getLen(int v) {
  int cnt = 0;
  while (!used[v]) {
    cnt++;
    used[v] = 1;
    v = a[v];
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    int l = getLen(i);
    b[m++] = make_pair(l, i);
  }
  sort(b, b + m);
  int it = 0;
  while (it < m) {
    if (b[it].first & 1) {
      int v = b[it].second;
      int u = v;
      for (int i = 0; i < b[it].first / 2 + 1; i++) u = a[u];
      do {
        ans[v] = u;
        v = a[a[v]];
        u = a[a[u]];
      } while (v != b[it].second);
      it++;
    } else if (it == m - 1 || b[it].first != b[it + 1].first)
      Fail();
    else {
      int v = b[it].second, u = b[it + 1].second;
      for (int i = 0; i < b[it].first; i++) {
        ans[v] = u;
        v = a[v];
        ans[u] = v;
        u = a[u];
      }
      it += 2;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}
