#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[10010];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n + m; i++) arr[i] = make_pair(0, 0);
  int d, x, a;
  for (int i = 1; i <= k; i++) {
    cin >> d >> x >> a;
    if (d == 2) x += n;
    arr[x] = make_pair(a, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j > 1) cout << " ";
      if (arr[i].second > arr[n + j].second)
        cout << arr[i].first;
      else
        cout << arr[n + j].first;
    }
    cout << endl;
  }
  return 0;
}
