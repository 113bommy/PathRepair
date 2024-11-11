#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
pair<int, int> a[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n > 4) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    cout << i << ' ' << i * i << endl;
  }
  for (int i = 1; i <= n - m; i++) {
    cout << i << ' ' << -i * i - 100000 << endl;
  }
}
