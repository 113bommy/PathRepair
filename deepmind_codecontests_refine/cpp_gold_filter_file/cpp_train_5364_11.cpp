#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, p;
  long long init = 0, pw = 0;
  string s;
  scanf("%d %d", &n, &p);
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s != "half") init += (1ll << pw);
    pw++;
  }
  long long ans = 0;
  while (init != 0) {
    if (init % 2 == 0) {
      ans += p * (init / 2);
    } else
      ans += p * (init / 2) + p / 2;
    init = init / 2;
  }
  cout << ans << endl;
  return 0;
}
