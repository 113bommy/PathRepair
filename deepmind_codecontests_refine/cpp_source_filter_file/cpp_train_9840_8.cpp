#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
long long a[N], b[N];
vector<pair<int, int> > val[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + 1ll * x;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    b[i] = b[i - 1] + 1ll * x;
  }
  bool sw = false;
  if (a[n] > b[n]) {
    swap(a, b);
    sw = true;
  }
  int j = 0;
  for (int i = 1; i <= n; i++) {
    while (b[j] < a[i]) j++;
    val[a[i] - b[j - 1]].push_back(make_pair(i, j - 1));
  }
  for (int i = 0; i < n; i++) {
    if (val[i].size() >= 2) {
      pair<int, int> x = val[i][0];
      pair<int, int> y = val[i][1];
      if (!sw) {
        cout << y.first - x.first << '\n';
        for (int j = x.first + 1; j <= y.first; j++) cout << j << ' ';
        cout << '\n';
        cout << y.second - x.second << '\n';
        for (int j = x.second + 1; j <= y.second; j++) cout << j << ' ';
      } else {
        cout << y.second - x.second << '\n';
        for (int j = x.second + 1; j <= y.second; j++) cout << j << ' ';
        cout << '\n';
        cout << y.first - x.first << '\n';
        for (int j = x.first + 1; j <= y.first; j++) cout << j << ' ';
      }
      return 0;
    }
  }
  cout << -1;
}
