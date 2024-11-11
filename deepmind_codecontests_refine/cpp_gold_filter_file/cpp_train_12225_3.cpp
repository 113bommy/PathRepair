#include <bits/stdc++.h>
using namespace std;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1}, inf = 2147483647;
const long long ll = 9223372036854775807;
int main() {
  int a, b;
  while (cin >> a >> b) {
    string ans = "";
    int ok = 0;
    for (int i = 1; i <= 9; i++) {
      string now = "";
      now += char(i + '0');
      int l = i, r = 0;
      for (int j = 1; j <= a; j++) {
        int k = l;
        k *= b;
        int t = k;
        l = t % 10 + r;
        r = k / 10;
        r += l / 10;
        l %= 10;
        now += char(l + '0');
      }
      reverse(now.begin(), now.end());
      if (now[1] == '0') {
        continue;
      }
      if (now[0] == (now[now.size() - 1]) && r == 0) {
        for (int i = 1; i < now.size(); i++) cout << now[i];
        cout << '\n';
        ok = 1;
        break;
      }
    }
    if (!ok) cout << "Impossible" << '\n';
  }
  return 0;
}
