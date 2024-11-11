#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 5;
bool a[N];
bool ask(int y) {
  cout << y << endl;
  fflush(stdout);
  int ret;
  cin >> ret;
  if (!ret) exit(0);
  return ret == 1;
}
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; ++i) a[i] = ask(1 << 30) ^ 1;
  int mid, L = 1, R = m, p = 0, ans;
  while (R >= L) {
    mid = (L + R) >> 1;
    if (ask(mid) ^ a[p])
      ans = mid, R = mid - 1;
    else
      L = mid + 1;
    p = (p + 1) % n;
  }
  ask(ans);
}
