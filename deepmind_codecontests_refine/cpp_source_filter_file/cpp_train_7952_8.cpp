#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1000;
const int M_MAX = N_MAX / 2;
int n, m;
int a[M_MAX];
int b[M_MAX];
bool used[N_MAX + 1];
void solve() {
  for (int i = 0; i < (m); ++i) used[a[i]] = true;
  for (int i = 0; i < (m); ++i) used[b[i]] = true;
  int r;
  for (int i = 0; i < (n); ++i)
    if (!used[i + 1]) r = i + 1;
  int k = n - 1;
  cout << k << endl;
  for (int i = 0; i < (k); ++i)
    if (i + 1 != r) cout << (i + 1) << ' ' << r << endl;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < (m); ++i) cin >> a[i] >> b[i];
  solve();
  return 0;
}
