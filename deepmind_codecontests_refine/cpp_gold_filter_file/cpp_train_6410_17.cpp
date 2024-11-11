#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = int(1e3);
long long int arr[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, k, x, y, ini;
  cin >> n >> m >> k >> x >> y;
  if (n == 1) {
    ini = k / (m);
    k %= m;
    x--;
    y--;
    for (int j = (int)0; j < (int)m; j++)
      if (k) arr[0][j]++, k--;
    cout << ini + arr[0][0] << " " << ini << " " << ini + arr[x][y] << endl;
    return 0;
  } else {
    ini = k / (2 * m * (n - 1));
    k %= 2 * m * (n - 1);
  }
  for (int i = (int)0; i < (int)n; i++) {
    for (int j = (int)0; j < (int)m; j++) {
      if (k) arr[i][j]++, k--;
    }
  }
  for (long long int i = n - 2; i >= 0; i--) {
    for (int j = (int)0; j < (int)m; j++) {
      if (k) arr[i][j]++, k--;
    }
  }
  long long int mxx1 = 0, mxx2 = 0, mnn1 = LLONG_MAX, mnn2 = LLONG_MAX;
  for (int i = (int)1; i < (int)n - 1; i++) {
    for (int j = (int)0; j < (int)m; j++) {
      mxx2 = max(mxx2, arr[i][j]);
      mnn2 = min(mnn2, arr[i][j]);
    }
  }
  for (int j = (int)0; j < (int)m; j++) {
    mxx1 = max(mxx1, max(arr[0][j], arr[n - 1][j]));
    mnn1 = min(mnn1, min(arr[0][j], arr[n - 1][j]));
  }
  long long int an1 = ini + mxx1, an2 = ini + mnn1;
  if (mnn2 != LLONG_MAX) {
    an1 = max(an1, 2 * ini + mxx2);
    an2 = min(an2, 2 * ini + mnn2);
  }
  x--;
  y--;
  if (x != 0 && x != n - 1) ini *= 2;
  cout << an1 << " " << an2 << " " << ini + arr[x][y] << endl;
  return 0;
}
