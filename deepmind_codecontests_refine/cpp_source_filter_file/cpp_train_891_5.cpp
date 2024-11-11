#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 100;
const long long LLINF = (long long)1e18 * 1LL + 10;
const double pi = acos(-1.0);
template <typename T1, typename T2>
bool umin(T1 &x, T2 y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, T2 y) {
  if (x < y) return x = y, true;
  return false;
}
template <typename T>
T getint() {
  char c = getchar();
  T p = 1, x = 0;
  while (c == ' ' || c == '\n') c = getchar();
  if (c == '-') p = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * p;
}
int n, m, k;
int a[N][3], c[N], d[N], use[N][3];
void dfs(int pos, int pl) {
  vector<int> next;
  for (int i = 0; i < (pl ? m : k); ++i) next.push_back((pl ? c[i] : d[i]));
  for (int i = 0; i < next.size(); ++i) {
    int to = pos - next[i];
    if (to <= 0) to = n - abs(to);
    if (a[pos][pl] == 2) {
      if (!a[to][pl ^ 1]) {
        a[to][pl ^ 1] = 1;
        dfs(to, pl ^ 1);
      }
    }
    if (a[pos][pl] == 1) {
      use[to][pl ^ 1]--;
      if (!use[to][pl ^ 1] && !a[to][pl ^ 1]) {
        a[to][pl ^ 1] = 2;
        dfs(to, pl ^ 1);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> d[i];
  }
  for (int i = 2; i <= n; ++i) {
    use[i][0] = m;
    use[i][1] = k;
  }
  a[1][0] = 2;
  a[1][1] = 2;
  dfs(1, 0);
  dfs(1, 1);
  for (int i = 2; i <= n; ++i) {
    if (a[i][0] == 0) {
      cout << "Loop ";
    }
    if (a[i][0] == 1) {
      cout << "Win ";
    }
    if (a[i][0] == 2) {
      cout << "Loose ";
    }
  }
  cout << endl;
  for (int i = 2; i <= n; ++i) {
    if (a[i][1] == 0) {
      cout << "Loop ";
    }
    if (a[i][1] == 1) {
      cout << "Win ";
    }
    if (a[i][1] == 2) {
      cout << "Loose ";
    }
  }
  return 0;
}
