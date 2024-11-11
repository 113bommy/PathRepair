#include <bits/stdc++.h>
const int N = 2e5 + 100;
long long W[N], T[N];
void out() {
  printf("-1\n");
  exit(0);
}
int main() {
  std::vector<long long> ans;
  int n;
  long long r;
  scanf("%d%I64d", &n, &r);
  for (int i = 0; i < n; i++) scanf("%I64d", W + i);
  for (int i = 0; i < n; i++) scanf("%I64d", T + i);
  long long cur = 0;
  long long left = 0;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    long long w = W[i], t = T[i];
    long long pre = std::min(w, left);
    left -= pre;
    w -= pre;
    cur += pre;
    t -= pre;
    if (t < 0)
      out();
    else if (w > t)
      out();
    else if (2 * w <= t) {
      cur += 2 * w;
      continue;
    } else {
      long long dt = 2ll * w - t;
      cur += (t - dt);
      w -= (t - dt) / 2;
      long long count = (dt + r - 1) / r;
      long long cc = count;
      cnt += count;
      if (count + ans.size() <= 1e5) {
        long long ww = w;
        while (count--) {
          ans.push_back(cur);
          long long dis = std::min(r, ww);
          ww -= dis;
          cur += dis;
        }
      } else
        cur += w;
      left += cc * r - w;
    }
  }
  printf("%I64d\n", cnt);
  if (cnt <= 1e5)
    for (int i = 0; i < ans.size(); i++) printf("%I64d ", ans[i]);
  return 0;
}
