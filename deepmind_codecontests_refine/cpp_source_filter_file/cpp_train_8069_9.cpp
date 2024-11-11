#include <bits/stdc++.h>
using namespace std;
const int maxn = 3333;
struct point {
  int x, y;
  friend bool operator<(point a, point b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
  }
} A[maxn], B[maxn];
int R, C, n, m, top;
int nxt[maxn], pre[maxn], cnt[maxn];
long long tmp, ans;
vector<int> v[maxn];
void dfs(int x, int k) {
  tmp -= B[x].y * cnt[x];
  tmp += B[pre[x]].y * cnt[x];
  if (pre[x] && k > 1) dfs(pre[x], k - 1);
  if (pre[x]) cnt[pre[x]] += cnt[x];
  cnt[x] = 0;
}
int main() {
  cin >> R >> C >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> A[i].x >> A[i].y;
  sort(A + 1, A + 1 + n);
  for (int up = (1); up <= (R); ++up) {
    top = 0;
    for (int i = (1); i <= (R); ++i) v[i].clear();
    for (int i = (1); i <= (R); ++i)
      if (A[i].x >= up) {
        B[++top] = A[i];
        cnt[top] = 0;
        pre[top] = top - 1;
        nxt[top] = top + 1;
        v[A[i].x].push_back(top);
      }
    tmp = 0;
    int j = 0;
    for (int i = (1); i <= (C); ++i) {
      while (j + 1 <= top && B[j + 1].y <= i) ++j;
      if (j - m + 1 > 0) tmp += B[j - m + 1].y, cnt[j - m + 1]++;
    }
    ans += tmp;
    for (int down = R; down > up; --down) {
      for (int x : v[down]) {
        dfs(x, m);
        pre[nxt[x]] = pre[x];
        nxt[pre[x]] = nxt[x];
      }
      ans += tmp;
    }
  }
  cout << ans << endl;
}
