#include <bits/stdc++.h>
using namespace std;
void _ad(int &p) {
  static int i = 0;
  p = i++;
}
int n, m;
int timeq[1000001] = {0};
int main() {
  int n;
  int t, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t >> c;
    timeq[t] = c;
  }
  long long q = 0;
  long long ans2 = 0, ans1 = -1;
  for (int i = 1; i <= 1000000; i++) {
    if (q > 0) {
      q--;
      if (q == 0) ans1 = i;
    }
    if (timeq[i] != 0) {
      q += timeq[i];
    }
    ans2 = max(ans2, q);
  }
  if (ans1 == -1) {
    ans1 = 1000000;
    ans1 += q;
  }
  cout << ans1 << " " << ans2;
  return 0;
}
