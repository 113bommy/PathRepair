#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
using namespace std;
clock_t start_time, end_time;
void open() {
  ((void)0);
  ((void)0);
  ((void)0);
  ((void)0);
}
void close() {
  ((void)0);
  ((void)0);
}
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const long double ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int t, n;
int main(int argc, char *argv[]) {
  open();
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    puts(n % 4 ? "NO" : "YES");
  }
  close();
  return 0;
}
