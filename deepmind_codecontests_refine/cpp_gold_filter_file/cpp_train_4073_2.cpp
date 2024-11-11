#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
time_t start, e_nd;
using namespace std;
inline long long int read() {
  long long int x = 0;
  static long long int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
  return x;
}
long long int n, box, sze, arr[200005];
bool is_possible(long long int suru) {
  long long int khali = box;
  long long int i = suru;
  while (i < n) {
    if (!khali) return false;
    long long int now_sa = 0;
    while (now_sa < sze) {
      now_sa += arr[i];
      i++;
    }
    khali--;
    if (now_sa > sze) i--;
  }
  return true;
}
void solve(int tt);
int main() {
  int tt = 1;
  for (long long int(i) = (0); i < (long long int)(tt); i++) solve(i + 1);
}
void solve(int tt) {
  n = read();
  box = read();
  sze = read();
  for (long long int(i) = (0); i < (long long int)(n); i++) arr[i] = read();
  long long int lo = 0, hi = n - 1;
  long long int ans = -1;
  while (lo <= hi) {
    long long int mid = (lo + hi) >> 1;
    if (is_possible(mid)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << n - ans << endl;
}
