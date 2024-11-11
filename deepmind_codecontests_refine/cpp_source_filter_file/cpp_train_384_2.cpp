#include <bits/stdc++.h>
using namespace std;
int n;
int a[110];
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n / 2; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  int now = 1;
  int ans = 0;
  for (int i = 1; i <= n / 2; i++) {
    int t = a[i] - now;
    if (t < 0) {
      t = -t;
    }
    ans += t;
    now += 2;
  }
  int mn = ans;
  ans = 0;
  now = 2;
  for (int i = 1; i <= n / 2; i++) {
    int t = a[i] - now;
    if (t < 0) {
      t = -t;
    }
    ans += t;
    now += 2;
  }
  mn = min(mn, ans);
  std::cout << mn << '\n';
  return 0;
}
