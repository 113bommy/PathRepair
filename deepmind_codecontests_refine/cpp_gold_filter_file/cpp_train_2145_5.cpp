#include <bits/stdc++.h>
using namespace std;
int cmp(const int q, const int w) { return q > w; }
int n, k;
int a[205];
int b[205];
int main() {
  bool flag = 0;
  int mmax = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < a[i - 1] && a[i] != 0) flag = 1;
  }
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
    mmax = max(mmax, b[i]);
  }
  if (flag == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  int j = 0;
  sort(b + 1, b + k + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) a[i] = b[++j];
    if (i == 1) continue;
    if (a[i] < a[i - 1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
