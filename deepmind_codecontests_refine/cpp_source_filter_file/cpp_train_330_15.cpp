#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int all[n], cont = 1, g = 0, s = 0, b = 0;
    vector<int> num;
    cin >> all[0];
    for (int i = 1; i < n; i++) {
      cin >> all[i];
      if (all[i] == all[i - 1])
        cont++;
      else {
        num.push_back(cont);
        cont = 1;
      }
    }
    num.push_back(cont);
    if (n >= 10) {
      int siz = num.size(), best = n / 2;
      g = num[0];
      best -= g;
      int cur = 1;
      if (cur < siz)
        while (best - num[cur] > 0 && cur + 1 < siz) {
          if (s > g)
            break;
          else {
            s += num[cur];
            best -= num[cur];
            cur++;
          }
        }
      if (cur < siz)
        while (best - num[cur] >= 0 && cur + 1 < siz) {
          b += num[cur];
          best -= num[cur];
          cur++;
        }
      if (b == 0 || s == 0 || b < g || s < g) {
        cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
        continue;
      }
    }
    cout << g << ' ' << s << ' ' << b << '\n';
  }
  return 0;
}
