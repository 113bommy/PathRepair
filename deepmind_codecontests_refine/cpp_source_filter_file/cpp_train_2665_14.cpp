#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;
int n, m;
int ask(int x, int y) {
  if (x <= 0 || y > n || x > n || y <= 0) return 0;
  printf("1 %d %d\n", x, y);
  fflush(stdout);
  string s;
  cin >> s;
  return s == "TAK";
}
void finish(int x, int y) {
  printf("2 %d %d", x, y);
  fflush(stdout);
  exit(0);
}
int get(int l, int r) {
  if (l > r) return 0;
  while (l < r) {
    int mid = l + r >> 1;
    if (ask(mid, mid + 1)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  scanf("%d %d", &n, &m);
  int ans1 = get(1, n), ans2;
  int t1 = get(1, ans1 - 1);
  int t2 = get(ans1 + 1, n);
  if (t1 != ans1 && ask(t1, t2))
    ans2 = t1;
  else
    ans2 = t2;
  finish(ans1, ans2);
}
