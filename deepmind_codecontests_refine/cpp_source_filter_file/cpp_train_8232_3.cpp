#include <bits/stdc++.h>
using namespace std;
void op(int a, int b) {
  int ta, tb, fa, fb, ans;
  cin >> ta >> fa >> tb >> fb;
  if (ta == tb)
    ans = abs(fa - fb);
  else {
    ans = abs(ta - tb);
    if (fa < a && fb < a) {
      ans += abs(fa - a) + abs(fb - a);
    } else if (fa > b && fb > b) {
      ans += abs(fa - b) + abs(fb - b);
    } else {
      ans += abs(fa - fb);
    }
  }
  cout << ans;
}
int main() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  for (int i = 0; i < k; i++) {
    op(a, b);
  }
}
