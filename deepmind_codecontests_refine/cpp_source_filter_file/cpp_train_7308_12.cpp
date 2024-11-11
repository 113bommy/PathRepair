#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int N;
int p[maxn], ip[maxn];
long long sum[maxn << 2][2];
void update(int ver, int pos, int val) {
  while (pos <= N) {
    sum[pos][ver] += val;
    pos += pos & (-pos);
  }
}
long long ask(int ver, int pos) {
  int ret = 0;
  while (pos) {
    ret += sum[pos][ver];
    pos -= pos & (-pos);
  }
  return ret;
}
long long query(int ver, int l, int r) { return ask(ver, r) - ask(ver, l - 1); }
int find_mid(int x) {
  int l = 1, r = N, ret = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ask(0, mid) >= x) {
      ret = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &p[i]);
    ip[p[i]] = i;
  }
  long long cnt = 0;
  for (int i = 1; i <= N; ++i) {
    cnt += query(0, ip[i], N);
    update(0, ip[i], 1);
    update(1, ip[i], ip[i]);
    long long ret = 0;
    long long mid = find_mid((i + 1) / 2);
    long long l = ask(0, mid - 1), r = i - l - 1;
    ret += mid * l - query(1, 1, mid - 1) - l * (l + 1) / 2;
    ret += -mid * r + query(1, mid + 1, N) - r * (r + 1) / 2;
    printf("%lld ", ret + cnt);
  }
  printf("\n");
}
