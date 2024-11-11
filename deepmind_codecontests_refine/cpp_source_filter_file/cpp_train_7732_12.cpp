#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, count = 0, night = 360, morning = 720, time = 10;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    time += a[i];
    if (time >= morning) break;
    count++;
    if (time <= night) continue;
    ans += time - night;
  }
  cout << count << " " << ans;
  return 0;
}
