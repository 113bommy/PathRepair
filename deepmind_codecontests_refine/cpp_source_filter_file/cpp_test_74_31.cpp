#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N], b[N], ban[N];
void solve(int x, int y, int z) {
  assert((x + y + z) % 2 == 0);
  b[1] = (y + z - x) / 2;
  b[2] = (x + z - y) / 2;
  b[3] = (x + y - z) / 2;
}
void calc(int hav) {
  for (int i = 1; i <= n; i++) {
    if (!ban[i]) {
      b[hav + 1] = a[i] - b[hav];
      ++hav;
    }
  }
  assert(hav == n);
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", b[i]);
  puts("");
  exit(0);
}
map<int, int> mp;
void dfs(int u, int S, int cnt, int sum) {
  if (m - u + 1 < cnt) return;
  if (u == m + 1) {
    assert(!cnt);
    if (mp[sum]) {
      int T = mp[sum];
      int both = S & T;
      S -= both;
      T -= both;
      stack<int> s1, s2;
      for (int i = 1; i <= n; i++) {
        if (S >> (i - 1) & 1) {
          ban[i] = 1;
          s1.push(a[i]);
        }
      }
      for (int i = 1; i <= n; i++) {
        if (T >> (i - 1) & 1) {
          ban[i] = 1;
          s2.push(a[i]);
        }
      }
      int tot = 1;
      while (!s1.empty()) {
        b[tot + 1] = s1.top() - b[tot];
        ++tot, s1.pop();
        b[tot + 1] = s2.top() - b[tot];
        ++tot, s2.pop();
      }
      calc(--tot);
    }
    mp[sum] = S;
  }
  dfs(u + 1, S, cnt, sum);
  if (cnt) dfs(u + 1, S | (1 << (u - 1)), cnt - 1, sum + a[u]);
}
int main() {
  scanf("%d", &n);
  stack<int> s[2];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[a[i] & 1].push(i);
  }
  if (n == 1) {
    printf("YES\n%d\n", a[1]);
    return 0;
  }
  if (n == 2) {
    if (a[1] == a[2])
      printf("YES\n0 %d\n", a[1]);
    else
      puts("NO");
    return 0;
  }
  bool gone = false;
  if (s[0].size() >= 3) {
    int x = s[0].top();
    s[0].pop();
    int y = s[0].top();
    s[0].pop();
    int z = s[0].top();
    s[0].pop();
    ban[x] = ban[y] = ban[z] = 1;
    solve(a[x], a[y], a[z]), gone = true;
  } else if (s[0].size() >= 1 && s[1].size() >= 2) {
    int x = s[0].top();
    s[0].pop();
    int y = s[1].top();
    s[1].pop();
    int z = s[1].top();
    s[1].pop();
    ban[x] = ban[y] = ban[z] = 1;
    solve(a[x], a[y], a[z]), gone = true;
  }
  if (gone) calc(3);
  if (n == 3) {
    puts("NO");
    return 0;
  }
  assert(s[0].empty());
  m = min(n, 26);
  if (n <= 26) {
    for (int i = 1; i <= n; i++) {
      mp.clear();
      dfs(1, 0, i, 0);
    }
    puts("NO");
    return 0;
  }
  dfs(1, 0, 26, 0);
  return 0;
}
