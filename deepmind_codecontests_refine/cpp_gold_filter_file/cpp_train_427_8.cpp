#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, c[N], t[N], dc[N], dt[N];
bool solve() {
  if (c[0] != t[0]) return false;
  for (int i = 0; i < n - 1; i++) {
    dc[i] = c[i + 1] - c[i];
    dt[i] = t[i + 1] - t[i];
  }
  sort(dc, dc + n - 1);
  sort(dt, dt + n - 1);
  for (int i = 0; i < n - 1; i++)
    if (dc[i] != dt[i]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  if (solve())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
