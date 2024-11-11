#include <bits/stdc++.h>
using namespace std;
void maloosh_lazma() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  maloosh_lazma();
  int n;
  cin >> n;
  long long x, tot = 0, cnt = 0, min = 9999999999999;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0) {
      tot += x;
    } else {
      tot += x;
      cnt++;
      if (x < min) min = x;
    }
  }
  if (cnt % 2 != 0) tot -= min;
  cout << tot;
  return 0;
}
