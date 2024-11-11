#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int INF = 1000 * 1000 * 1000;
long long a[N];
long long old_a[N];
long long que[N][5];
long long ogr[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    ogr[i] = INF;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> que[i][j];
    }
    if (que[i][1] == 1) {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        a[j] += que[i][4];
      }
    } else {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        ogr[j] = min(ogr[j], que[i][4] - a[j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = ogr[i];
  }
  for (int i = 1; i <= m; i++) {
    if (que[i][1] == 1) {
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        a[j] += que[i][4];
      }
    } else {
      bool ok = false;
      for (int j = que[i][2]; j <= que[i][3]; j++) {
        ok |= (a[j] == que[i][4]);
      }
      if (!ok) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ogr[i] << " ";
  }
  cout << endl;
  return 0;
}
