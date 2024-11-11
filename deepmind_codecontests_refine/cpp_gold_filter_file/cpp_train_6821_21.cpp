#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
pair<long long, long long> b[50055];
pair<long long, long long> a[50050];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  long long v, r, c;
  for (int i = 0; i < 50050; i++)
    a[i].first = b[i].first = -1, a[i].second = b[i].second = 0;
  for (int i = 0; i < k; i++) {
    cin >> v >> r >> c;
    if (v == 1) {
      b[r].first = i;
      b[r].second = c;
    } else {
      a[r].first = i;
      a[r].second = c;
    }
  }
  for (int j = 1; j <= n; j++, cout << endl)
    for (int i = 1; i <= m; i++) {
      cout << (a[i].first > b[j].first ? a[i].second : b[j].second) << " ";
    }
}
