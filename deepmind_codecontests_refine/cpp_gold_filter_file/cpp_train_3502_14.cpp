#include <bits/stdc++.h>
using namespace std;
const int N = 1111;
pair<string, string> a[N], b[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].second += ";";
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[i].second == a[j].second) {
        cout << b[i].first << ' ' << b[i].second << " #" << a[j].first << '\n';
        break;
      }
    }
  }
}
