#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MAXN = (int)1e6 + 7;
const int INF = (int)1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n;
int A[MAXN], B[MAXN], a[MAXN], b[MAXN];
pair<int, int> second[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> second[i].first;
    second[i].second = i;
  }
  int x = (n + 2) / 3;
  sort(second + 1, second + n + 1);
  for (int i = 1; i <= x; i++) {
    a[i] = 0, b[i] = second[i].first;
  }
  for (int i = x + 1; i <= x + x; i++) {
    a[i] = second[i].first, b[i] = 0;
  }
  int cnt = x;
  for (int i = x + x + 1; i <= n; i++) {
    a[i] = cnt--;
    b[i] = second[i].first - a[i];
  }
  for (int i = 1; i <= n; i++) {
    A[second[i].second] = a[i];
    B[second[i].second] = b[i];
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << A[i] << ' ';
  cout << "\n";
  for (int i = 1; i <= n; i++) cout << B[i] << ' ';
  return 0;
}
