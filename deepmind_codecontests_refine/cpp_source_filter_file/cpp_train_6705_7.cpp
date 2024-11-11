#include <bits/stdc++.h>
using namespace std;
const int SQRT = 317;
const int MAXN = 1e5 + 5;
int n, m, q;
long long a[MAXN];
long long sol[SQRT], cnt[SQRT];
int id[MAXN];
vector<int> v[MAXN];
bool sijeku[SQRT][MAXN];
int sijekCnt[MAXN][SQRT];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(id, -1, sizeof(id));
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int idx = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      y--;
      v[i].push_back(y);
    }
    if (x >= SQRT) {
      long long sum = 0;
      for (auto it : v[i]) {
        sum += a[it];
        sijeku[idx][it] = true;
      }
      id[i] = idx;
      sol[idx] = sum;
      idx++;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (auto it : v[i]) {
      for (int j = 0; j < idx; ++j) {
        sijekCnt[i][j] += sijeku[j][it];
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    char c;
    cin >> c;
    if (c == '?') {
      int x;
      cin >> x;
      x--;
      if (id[x] == -1) {
        long long sum = 0;
        for (auto it : v[x]) sum += a[it];
        for (int j = 0; j < idx; ++j) sum += sijekCnt[x][j] * cnt[j];
        cout << sum << "\n";
      } else {
        cout << sol[x] << "\n";
      }
    } else {
      long long x, y;
      cin >> x >> y;
      x--;
      if (id[x] == -1) {
        for (auto it : v[x]) {
          a[it] += y;
        }
        for (int j = 0; j < idx; ++j) {
          sol[j] += y * sijekCnt[x][j];
        }
      } else {
        for (int j = 0; j < idx; ++j) {
          sol[j] += y * sijekCnt[x][j];
        }
        cnt[id[x]] += y;
      }
    }
  }
}
