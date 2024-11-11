#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
char s[N][N];
pair<int, int> a[N];
int sum, n, m;
void gofail() {
  cout << "no\n";
  exit(0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  sum = n * (n - 1);
  for (int i = 1; i <= n; ++i) a[i].second = i;
  for (int i = n - m + 1; i <= n; ++i) cin >> a[i].first, sum -= a[i].first;
  if (sum < 0) gofail();
  for (int i = 1; i <= n - m; ++i)
    a[i].first = sum / (n - m - i + 1), sum -= a[i].first;
  if (sum) gofail();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n - m; ++i)
    if (a[i].second > n - m) gofail();
  for (int i = 1; i <= n; ++i) {
    sum += a[i].first;
    if (sum < i * (i - 1)) gofail();
  }
  for (int i = n; i; --i) {
    sort(a + 1, a + i + 1);
    sum = a[i].first;
    int x = a[i].second;
    for (int j = 1; j < i; ++j) {
      int y = a[j].second;
      if (sum >= 2)
        sum -= 2, s[x][y] = 'W', s[y][x] = 'L';
      else if (sum == 1)
        --sum, --a[j].first, s[x][y] = s[y][x] = 'D';
      else
        a[j].first -= 2, s[x][y] = 'L', s[y][x] = 'W';
    }
  }
  cout << "yes\n";
  for (int i = 1; i <= n; ++i) {
    s[i][i] = 'X';
    cout << (s[i] + 1) << '\n';
  }
  return 0;
}
