#include <bits/stdc++.h>
using namespace std;
long long arr[500010];
long long brr[500010];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> m >> n;
  vector<pair<int, int>> v;
  int a, b, c;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      for (int j = b + 1; j <= c; j++) arr[j] = 1;
    } else
      v.push_back({b, c});
  }
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].first, y = v[i].second;
    int b = 0;
    for (int j = x + 1; j <= y; j++) {
      if (arr[j] == 1) b = 1;
    }
    if (b == 1) {
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
  int p = 300000;
  for (int i = 1; i <= m; i++) {
    if (arr[i] == 0) p--;
    cout << p << endl;
  }
}
