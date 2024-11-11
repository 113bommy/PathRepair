#include <bits/stdc++.h>
using namespace std;
const int N = 3333;
const long long INF = 1e9 + 19;
int n, m;
int a[N];
int aa[N];
int c[N];
char ans[N][N];
bool use[N];
void read() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) aa[i] = a[i];
}
void solve() {
  int Z = 0;
  for (int i = 0; i < n; i++) {
    Z += a[i];
  }
  if (m - n > 0) {
    int sum = m * (m - 1) * 2 - Z;
    int t = sum / (m - n);
    int rem = sum % (m - n);
    for (int i = n; i < m; i++) {
      a[i] = t;
      if (i - n < rem) a[i]++;
    }
  }
  for (int i = 0; i < m; i++) {
    a[i] -= (m - 1);
  }
  int ss = 0;
  for (int i = 0; i < m; i++) ss += a[i];
  for (int i = 0; i < m; i++) {
    int mx = -1;
    for (int j = 0; j < m; j++)
      if (!use[j] && (mx == -1 || abs(a[j]) > abs(a[mx]))) {
        mx = j;
      }
    assert(mx != -1);
    vector<pair<int, int>> other;
    for (int j = 0; j < m; j++) {
      if (!use[j] && j != mx) other.push_back(make_pair(a[j], j));
    }
    sort((other).begin(), (other).end());
    for (int j = 0; j < (int)other.size(); j++) {
      if (((int)other.size() - j - 1) + (a[mx] - 1) >= 0) {
        a[mx]--;
        a[other[j].second]++;
        ans[mx][other[j].second] = 'W';
        ans[other[j].second][mx] = 'L';
      } else if (((int)other.size() - j - 1) + a[mx] >= 0) {
        ans[mx][other[j].second] = 'D';
        ans[other[j].second][mx] = 'D';
      } else {
        a[mx]++;
        a[other[j].second]--;
        ans[mx][other[j].second] = 'L';
        ans[other[j].second][mx] = 'W';
      }
    }
    use[mx] = 1;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      if (ans[i][j] == 'W') c[i] += 2;
      if (ans[i][j] == 'D') c[i] += 1;
    }
  for (int i = 0; i < m; i++) ans[i][i] = 'X';
  sort(c, c + m);
  reverse(c, c + m);
  bool ok = 1;
  for (int i = 0; i < n; i++) ok &= c[i] == aa[i];
  if (ok) {
    puts("yes");
    for (int i = 0; i < m; i++) printf("%s\n", ans[i]);
  } else {
    puts("no");
  }
}
void stress() {}
int main() {
  if (1) {
    read();
    solve();
  } else {
    stress();
  }
  return 0;
}
