#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> sum;
int n, k;
bool check_first() {
  for (int i = 1; i + k - 1 <= n; ++i) {
    if (sum[i - 1] == 0 && sum[n] - sum[i + k - 1] == 0) return true;
    if (sum[i - 1] + sum[n] - sum[i + k - 1] == n - k) return true;
  }
  return false;
}
bool check_second() {
  if (k == 1 || 2 * k < n) return false;
  for (int i = 2; i <= n - k - 1; ++i) {
    if (a[i] != a[i - 1] || a[n - i + 1] != a[n - i + 2]) return false;
  }
  if (a[1] == a[n]) return false;
  return true;
}
int main() {
  cin >> n >> k;
  a.resize(n + 1);
  sum.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    char x;
    cin >> x;
    a[i] = x - '0';
    sum[i] = sum[i - 1] + a[i];
  }
  if (check_first())
    cout << "tokitsukaze" << endl;
  else if (check_second())
    cout << "quality" << endl;
  else
    cout << "once again" << endl;
}
