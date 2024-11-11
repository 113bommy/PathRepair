#include <bits/stdc++.h>
using namespace std;
int bad[1 << 20];
int a[100010];
int cnt[20];
int main() {
  int n, m, d;
  while (cin >> n >> m >> d) {
    for (int i = 0; i < m; i++) {
      int num, t;
      cin >> num;
      for (int j = 0; j < num; j++) {
        cin >> t;
        a[t - 1] = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i >= d) cnt[a[i - d]]--;
      cnt[a[i]]++;
      if (i >= d - 1) {
        int tmp = 0;
        for (int j = 0; j < m; j++)
          if (!cnt[j]) tmp |= (1 << j);
        bad[tmp] = 1;
      }
    }
    int sol = 1e9;
    for (int i = (1 << m) - 1; i > 0; i--) {
      if (bad[i]) {
        for (int j = 0; j < m; j++)
          if ((bad[i] >> j) & 1) bad[i - (1 << j)] = 1;
      } else {
        int w = 0;
        for (int j = 0; j < m; j++)
          if ((i >> j) & 1) w++;
        sol = min(sol, w);
      }
    }
    cout << sol << endl;
  }
  return 0;
}
