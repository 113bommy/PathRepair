#include <bits/stdc++.h>
using namespace std;
int n, a, b, x[105], y[105];
int Max;
void Get_val(int i, int j) { Max = max(Max, x[i] * y[i] + x[j] * y[j]); }
void Get_Max(int i, int j) {
  for (int k = 0; k < 2; ++k) {
    if (x[i] + x[j] <= b && max(y[i], y[j]) <= a) Get_val(i, j);
    swap(a, b);
  }
}
void solve(int i, int j) {
  int target;
  for (int k = 0; k < 4; ++k) {
    if (k % 4)
      target = j;
    else
      target = i;
    Get_Max(i, j);
    swap(x[target], y[target]);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) solve(i, j);
  cout << Max << endl;
  return 0;
}
