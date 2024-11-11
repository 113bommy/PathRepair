#include <bits/stdc++.h>
using namespace std;
int a[5][5];
pair<int, int> cost[5];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++) cin >> a[i][j];
  for (int i = 1; i <= 4; i++) {
    cost[i].first =
        min(a[i][1] + a[i][3],
            min(a[i][1] + a[i][4], min(a[i][2] + a[i][3], a[i][2] + a[i][4])));
    cost[i].second = i;
  }
  sort(cost + 1, cost + 5);
  if (cost[1].first > n)
    cout << -1;
  else {
    cout << cost[1].second << " ";
    int u = cost[1].second;
    if (cost[1].first == a[u][1] + a[u][3])
      cout << a[u][1] << " " << n - a[u][1];
    else if (cost[1].first == a[u][1] + a[u][4])
      cout << a[u][1] << " " << n - a[u][1];
    else if (cost[1].first == a[u][2] + a[u][3])
      cout << a[u][2] << " " << n - a[u][2];
    else
      cout << a[u][2] << " " << n - a[u][2];
  }
}
