#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
bool f1;
long long n, k;
int dig[30];
bool check(long long x) {
  register int tmp = 0;
  while (x) dig[++tmp] = x % 10, x /= 10;
  for (int i = 2; i < tmp; i++)
    if ((dig[i - 1] < dig[i] && dig[i] > dig[i + 1]) ||
        (dig[i - 1] > dig[i] && dig[i] < dig[i + 1]))
      continue;
    else
      return false;
  return true;
}
void slv1() {
  register int cnt = 0;
  for (long long i = n; i <= 1ll * 10000000 * 10000000; i += n) {
    if (check(i)) cnt++;
    if (cnt == k) {
      printf("%lld\n", i);
      return;
    }
  }
  puts("-1");
}
int high[1000000], tot = 0, id = 0, cnt[11][2][1000000], to[10000000];
vector<int> low[11][2];
void add_high(int i) {
  register int x = 0;
  while (i) x = x * 10 + dig[i], i--;
  high[++tot] = x;
}
void find_high(int now) {
  for (int i = 0; i <= 9; i++)
    if (i != dig[now - 1]) {
      if (now <= 2 ||
          (now > 2 && dig[now - 2] < dig[now - 1] && dig[now - 1] > i) ||
          (now > 2 && dig[now - 2] > dig[now - 1] && dig[now - 1] < i)) {
        dig[now] = i;
        if (i) add_high(now);
        if (now < 7) find_high(now + 1);
      }
    }
}
void add_low() {
  register int x = 0, i = 7;
  while (i) x = x * 10 + dig[i], i--;
  if (dig[7] < dig[6]) {
    low[dig[7]][0].push_back(x);
    if (!to[x % n]) to[x % n] = ++id;
    cnt[dig[7]][0][to[x % n]]++;
  } else {
    low[dig[7]][1].push_back(x);
    if (!to[x % n]) to[x % n] = ++id;
    cnt[dig[7]][1][to[x % n]]++;
  }
}
void find_low(int now) {
  for (int i = 0; i <= 9; i++)
    if (i != dig[now - 1]) {
      if (now <= 2 || (dig[now - 2] < dig[now - 1] && dig[now - 1] > i) ||
          (dig[now - 2] > dig[now - 1] && dig[now - 1] < i)) {
        dig[now] = i;
        if (now == 7)
          add_low();
        else
          find_low(now + 1);
      }
    }
}
void ans_find_low(int x, int hs) {
  for (int j = x % 10 + 1; j <= 9; j++)
    if (cnt[j][1][hs]) {
      if (k > cnt[j][1][hs])
        k -= cnt[j][1][hs];
      else {
        sort(low[j][1].begin(), low[j][1].end());
        for (int s = 0; s < low[j][1].size(); s++)
          if (to[low[j][1][s] % n] == hs) {
            k--;
            if (!k) {
              printf("%d%07d\n", x, low[j][1][s]);
              exit(0);
            }
          }
      }
    }
}
void ans_find_high(int x, int hs) {
  for (int j = 0; j < x % 10; j++)
    if (cnt[j][0][hs]) {
      if (k > cnt[j][0][hs])
        k -= cnt[j][0][hs];
      else {
        sort(low[j][0].begin(), low[j][0].end());
        for (int s = 0; s < low[j][0].size(); s++)
          if (to[low[j][0][s] % n] == hs) {
            k--;
            if (!k) {
              printf("%d%07d\n", x, low[j][0][s]);
              exit(0);
            }
          }
      }
    }
}
void slv2() {
  dig[0] = -1;
  find_high(1);
  find_low(1);
  sort(high + 1, high + 1 + tot);
  for (int i = 1; i <= tot; i++)
    if (high[i] % n == 0) {
      k--;
      if (!k) {
        printf("%d\n", high[i]);
        return;
      }
    }
  for (int i = 1; i <= tot; i++) {
    register int hs = to[n - 1ll * high[i] * 10000000 % n];
    if (!hs) continue;
    if (high[i] < 10)
      ans_find_high(high[i], hs), ans_find_low(high[i], hs);
    else {
      if (high[i] / 10 % 10 > high[i] % 10)
        ans_find_low(high[i], hs);
      else
        ans_find_high(high[i], hs);
    }
  }
  puts("-1");
}
bool f2;
signed main() {
  n = read(), k = read();
  if (n >= 10000000)
    slv1();
  else
    slv2();
  return 0;
}
