#include <bits/stdc++.h>
using namespace std;
long long INF = 1 << 28;
const double pi = acos(-1.0);
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int knight[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
const long double EPS = 1e-7;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool cmp(int a, int b) { return a < b; }
int on(int mask, int st) { return mask | (1 << st); }
int off(int mask, int st) { return mask & (~(1 << st)); }
bool check(int mask, int st) { return mask & (1 << st); }
long long inf = 1e18;
long long mod = 1e9 + 7;
int freq[(1 << 22) + 2];
int F[(1 << 22) + 2];
int arr[1000100];
int color;
int main() {
  int t;
  int a, b, n;
  t = 1;
  color++;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    arr[i] = a;
    freq[a]++;
  }
  long long ans = 0;
  for (int i = 0; i < (1 << 22); ++i) {
    F[i] = 0;
    if (freq[i]) F[i] = i;
  }
  for (int i = 0; i < 22; ++i)
    for (int mask = 0; mask < (1 << 22); ++mask) {
      if (mask & (1 << i)) F[mask] = max(F[mask], F[mask ^ (1 << i)]);
    }
  for (int i = 0; i < n; i++) {
    int other = arr[i] ^ ((1 << 22) - 1);
    a = F[other];
    if (a == 0) a = -1;
    printf("%d ", a);
  }
  return 0;
}
