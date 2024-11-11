#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) cin >> b[i];
  int cnt = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= b[j]) {
      cnt++;
      j++;
    }
  }
  cout << cnt << "\n";
}
