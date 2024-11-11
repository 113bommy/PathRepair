#include <bits/stdc++.h>
using namespace std;
long long int n, q;
long long int arr[200005];
long long int dist[22][22];
long long int mindist[200005][22];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
  for (long long int i = 0; i <= 20; i++) {
    for (long long int j = 0; j <= 20; j++) {
      if (i != j) dist[i][j] = INT_MAX;
    }
  }
  for (long long int i = n; i >= 1; i--) {
    vector<long long int> z, o;
    for (long long int j = 0; j <= 20; j++) {
      if (arr[i] & (1 << j)) {
        mindist[i][j] = 0;
        o.push_back(j);
        for (long long int k = 0; k <= 20; k++) {
          if (arr[i] & (1 << k)) dist[j][k] = 0;
        }
      } else
        z.push_back(j);
    }
    for (auto it0 : z) {
      long long int m = INT_MAX;
      for (auto it1 : o) {
        m = min(m, dist[it1][it0]);
      }
      for (auto it1 : o) {
        dist[it1][it0] = m;
      }
      mindist[i][it0] = m;
    }
    for (long long int j = 0; j <= 20; j++) {
      for (long long int k = 0; k <= 20; k++) dist[j][k]++;
    }
  }
  while (q--) {
    long long int x, y;
    cin >> x >> y;
    long long int m = INT_MAX;
    for (long long int j = 0; j <= 20; j++) {
      if (arr[y] & (1 << j)) m = min(m, mindist[x][j]);
    }
    if (m <= (y - x))
      cout << "Shi\n";
    else
      cout << "Fou\n";
  }
  return 0;
}
