#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flg = true;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
const long long INF = 9e18;
int n;
struct Node {
  long long x, y, z;
} node[100010];
bool check0(long long L0, long long R0, long long L1, long long R1,
            long long L2, long long R2, long long L3, long long R3, bool flg) {
  if (L0 % 2) L0++;
  if (R0 % 2) R0--;
  if (L0 > R0) return 0;
  if (L1 % 2) L1++;
  if (R1 % 2) R1--;
  if (L1 > R1) return 0;
  if (L2 % 2) L2++;
  if (R2 % 2) R2--;
  if (L2 > R2) return 0;
  if (L3 % 2) L3++;
  if (R3 % 2) R3--;
  if (L3 > R3) return 0;
  long long A = L0, B = L1, C = L2;
  if ((long double)A + B + C > R3) return 0;
  long long d = A + B + C >= L3 ? 0 : L3 - A - B - C;
  long long t = min(R0 - L0, d);
  d -= t;
  A += t;
  t = min(R1 - L1, d);
  d -= t;
  B += t;
  t = min(R2 - L2, d);
  d -= t;
  C += t;
  if (t) return 0;
  if (flg) printf("%I64d %I64d %I64d\n", (B + C) / 2, (A + C) / 2, (A + B) / 2);
  return 1;
}
bool check1(long long L0, long long R0, long long L1, long long R1,
            long long L2, long long R2, long long L3, long long R3, bool flg) {
  if (L0 % 2 == 0) L0++;
  if (R0 % 2 == 0) R0--;
  if (L0 > R0) return 0;
  if (L1 % 2 == 0) L1++;
  if (R1 % 2 == 0) R1--;
  if (L1 > R1) return 0;
  if (L2 % 2 == 0) L2++;
  if (R2 % 2 == 0) R2--;
  if (L2 > R2) return 0;
  if (L3 % 2 == 0) L3++;
  if (R3 % 2 == 0) R3--;
  if (L3 > R3) return 0;
  long long A = L0, B = L1, C = L2;
  if ((long double)A + B + C > R3) return 0;
  long long d = A + B + C >= L3 ? 0 : L3 - A - B - C;
  long long t = min(R0 - L0, d);
  d -= t;
  A += t;
  t = min(R1 - L1, d);
  d -= t;
  B += t;
  t = min(R2 - L2, d);
  d -= t;
  C += t;
  if (t) return 0;
  if (flg) printf("%I64d %I64d %I64d\n", (B + C) / 2, (A + C) / 2, (A + B) / 2);
  return 1;
}
bool check(long long k, bool flg = 0) {
  long long L0 = -INF, L1 = -INF, L2 = -INF, L3 = -INF;
  long long R0 = INF, R1 = INF, R2 = INF, R3 = INF;
  for (int i = 1; i <= n; i++) {
    R0 = min(R0, k - node[i].x + node[i].y + node[i].z);
    L0 = max(L0, -k - node[i].x + node[i].y + node[i].z);
    R1 = min(R1, k + node[i].x - node[i].y + node[i].z);
    L1 = max(L1, -k + node[i].x - node[i].y + node[i].z);
    R2 = min(R2, k + node[i].x + node[i].y - node[i].z);
    L2 = max(L2, -k + node[i].x + node[i].y - node[i].z);
    R3 = min(R3, k + node[i].x + node[i].y + node[i].z);
    L3 = max(L3, -k + node[i].x + node[i].y + node[i].z);
  }
  return check0(L0, R0, L1, R1, L2, R2, L3, R3, flg) ||
         check1(L0, R0, L1, R1, L2, R2, L3, R3, flg);
}
void init() {}
void solve() {
  n = read();
  for (int i = 1; i <= n; i++) node[i] = (Node){read(), read(), read()};
  long long l = 0, r = 3e18, mid, ans;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  check(ans, 1);
}
int main() {
  for (int T = read(); T--;) init(), solve();
  return 0;
}
