#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, t, lastH, cntH, res = -1;
;
vector<int> shop;
char s[N];
bool OK(int carry) {
  if (carry >= cntH) return lastH <= t;
  if (carry + (int)shop.size() < cntH) return false;
  int end = max(lastH, shop[cntH - carry - 1]);
  int tt = 1, T = t + 1;
  for (int i = 1; i <= n; i++) {
    T = min(T, tt + 2 * (end - i));
    if (s[i] == 'S')
      carry++;
    else if (s[i] == 'H')
      carry--;
    tt++;
    if (carry < 0) tt += 2;
  }
  return (T <= t);
}
int main() {
  cin >> n >> t;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] == 'H')
      lastH = i, cntH++;
    else if (s[i] == 'S')
      shop.push_back(i);
  int low = 0, high = cntH + 1, mid, res = -1;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (OK(mid)) {
      res = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << res << endl;
  return 0;
}
