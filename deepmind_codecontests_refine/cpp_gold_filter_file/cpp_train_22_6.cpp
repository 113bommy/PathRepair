#include <bits/stdc++.h>
using namespace std;
const int MAX = 80;
int f[MAX][MAX];
bool take[MAX][MAX];
void run_case() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      f[i][j] = -1000000000;
      take[i][j] = false;
    }
  }
  int n, k;
  cin >> n >> k;
  struct item {
    int first, second, ind;
  };
  vector<item> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].ind = i;
  }
  sort(a.begin(), a.end(),
       [&](const item& w, const item& v) { return w.second < v.second; });
  f[n][k] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      f[i][j] = f[i + 1][j] + a[i].second * (k - 1);
      int cost = f[i + 1][j + 1] + a[i].first + a[i].second * j;
      if (j < k && cost > f[i][j]) {
        f[i][j] = cost;
        take[i][j] = true;
      }
    }
  }
  cout << k + 2 * (n - k) << '\n';
  int j = 0;
  vector<int> taken, shrek;
  for (int i = 0; i < n; i++) {
    if (take[i][j]) {
      taken.push_back(i);
      j++;
    } else {
      shrek.push_back(i);
    }
  }
  assert(taken.size() == k);
  for (int i = 0; i + 1 < k; i++) cout << a[taken[i]].ind + 1 << ' ';
  for (int i = 0; i < n - k; i++)
    cout << a[shrek[i]].ind + 1 << ' ' << -a[shrek[i]].ind - 1 << ' ';
  cout << a[taken[k - 1]].ind + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) run_case();
  return 0;
}
