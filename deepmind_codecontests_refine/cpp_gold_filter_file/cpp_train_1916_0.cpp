#include <bits/stdc++.h>
using namespace std;
long long int apSum(long long int a, long long int n, long long int d = 1) {
  long long int res = (2 * a + (n - 1) * d) * n;
  res /= 2;
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int n, m;
bool isValid(long long int a, long long int b) {
  if (a < 0 || b < 0 || a >= n || b >= m) return false;
  return true;
}
void solve() {
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  vector<vector<bool>> mark(n, vector<bool>(m, false));
  vector<vector<bool>> flag(n, vector<bool>(m, false));
  pair<long long int, long long int> start, end;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') {
        start.first = i;
        start.second = j;
      }
      if (arr[i][j] == 'E') {
        end.first = i;
        end.second = j;
      }
    }
  }
  long long int len = 0, count = 0;
  queue<pair<long long int, long long int>> list;
  list.push(start);
  mark[start.first][start.second] = true;
  long long int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
  bool res = false;
  while (!list.empty() && res == false) {
    long long int s = list.size();
    while (!res && s--) {
      pair<long long int, long long int> temp = list.front();
      list.pop();
      for (long long int i = 0; i < 4; i++) {
        long long int a = temp.first + dx[i];
        long long int b = temp.second + dy[i];
        if (isValid(a, b) && mark[a][b] == false && arr[a][b] != 'T') {
          if (arr[a][b] == 'E') {
            res = true;
            break;
          }
          mark[a][b] = true;
          list.push({a, b});
        }
      }
    }
    len += 1;
  }
  res = false;
  long long int ans = 0;
  queue<pair<long long int, long long int>> path;
  path.push(end);
  flag[end.first][end.second] = true;
  while (!path.empty() && count < len) {
    long long int s = path.size();
    while (s--) {
      pair<long long int, long long int> temp = path.front();
      path.pop();
      for (long long int i = 0; i < 4; i++) {
        long long int a = temp.first + dx[i];
        long long int b = temp.second + dy[i];
        if (isValid(a, b) && flag[a][b] == false && arr[a][b] != 'T') {
          if (arr[a][b] != 'E' && arr[a][b] != 'S') {
            long long int v = arr[a][b] - 48;
            ans += v;
          }
          flag[a][b] = true;
          path.push({a, b});
        }
      }
    }
    count += 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int testCases = 1;
  while (testCases--) {
    solve();
  }
}
