#include <bits/stdc++.h>
using namespace std;
int p[4];
int a, b;
int main() {
  cin.sync_with_stdio(0);
  for (int i = 0; i < 4; i++) cin >> p[i];
  cin >> a >> b;
  if (a > b) swap(a, b);
  int ans = 0;
  while (a <= b) {
    sort(p, p + 4);
    int cnt = 0;
    do {
      int temp = a;
      for (int i = 0; i < 4; i++) temp %= p[i];
      if (temp == a) cnt++;
    } while (next_permutation(p, p + 4));
    ans += (cnt >= 7);
    a++;
  }
  cout << ans << endl;
  return 0;
}
