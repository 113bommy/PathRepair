#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
}
using namespace std;
int n;
int h[501000];
inline bool cmp(const int x, const int y) { return x > y; }
priority_queue<int, vector<int>, greater<int> > q;
int opt[501000 << 1], otot, cnt, ctmp;
inline void Update() {
  while (otot) q.push(opt[otot]), --otot;
  cnt += ctmp;
  ctmp = 0;
}
signed main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(h[i]);
  sort(h + 1, h + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    if (h[i] != h[i - 1]) Update();
    if (cnt) {
      opt[++otot] = h[i];
      --cnt;
      continue;
    }
    if (q.size() && h[i] > q.top()) {
      q.pop();
      opt[++otot] = h[i];
      ++cnt;
      continue;
    }
    if (q.size() && h[i] == h[i + 1] && h[i] + h[i] > q.top()) {
      opt[++otot] = q.top();
      opt[++otot] = h[i] + h[i] - q.top();
      q.pop();
      ++i;
      continue;
    }
    ++ctmp;
  }
  Update();
  long long ans = 0;
  while (q.size()) ans -= q.top(), q.pop();
  for (int i = 1; i <= n; ++i) ans += h[i];
  printf("%lld\n", ans);
  return 0;
}
