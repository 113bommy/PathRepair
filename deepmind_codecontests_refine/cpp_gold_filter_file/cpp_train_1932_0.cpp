#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  int now[300001], ost[300001];
  int quer[300010];
  int maxt = 0;
  for (int i = 0; i < n; i++) {
    now[i] = ost[i] = 0;
  }
  int ans = 0;
  int st = 0;
  for (int i = 0; i < q; i++) {
    int type, val;
    cin >> type >> val;
    if (type == 1) {
      now[val - 1]++;
      ans++;
      quer[st] = val - 1;
      st++;
    }
    if (type == 2) {
      ost[val - 1] += now[val - 1];
      ans -= now[val - 1];
      now[val - 1] = 0;
    }
    if (type == 3) {
      for (int j = maxt; j < val; j++) {
        if (ost[quer[j]] > 0)
          ost[quer[j]]--;
        else {
          now[quer[j]]--;
          ans--;
        }
      }
      maxt = max(maxt, val);
    }
    cout << ans << endl;
  }
}
