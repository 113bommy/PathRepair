#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
int T;
int N;
VI a;
VVI c, aib;
void ReadData();
void Solve();
void Update(int i, int j, int val);
int Query(int i, int j);
int main() {
  cin >> T;
  while (T--) {
    ReadData();
    Solve();
  }
  return 0;
}
void ReadData() {
  cin >> N;
  a = VI(N + 1);
  for (int i = 1; i <= N; ++i) cin >> a[i];
}
void Solve() {
  c = VVI(N + 1, VI(N + 1));
  for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j)
      if (a[i] == a[j]) c[i][j] = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) c[i][j] += c[i - 1][j];
  aib = VVI(N + 1, VI(N + 1));
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (c[i][j]) Update(i, j, c[i][j]);
  long long ans{0};
  for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j)
      if (a[i] == a[j]) {
        int p1 = i + 1;
        int p2 = j - 1;
        int v = j + 1;
        int t1 = Query(p2, N) - Query(p2, v - 1);
        int t2 = Query(p1 - 1, N) - Query(p1 - 1, v - 1);
        ans += t1 - t2;
      }
  cout << ans << '\n';
}
void Update(int i, int j, int val) {
  for (int p = j; p <= N; p += p & -p) aib[i][p] += val;
}
int Query(int i, int j) {
  int ans{0};
  for (int p = j; p > 0; p -= p & -p) ans += aib[i][p];
  return ans;
}
