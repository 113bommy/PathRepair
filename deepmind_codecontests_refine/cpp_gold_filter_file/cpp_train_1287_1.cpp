#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += v[i];
  }
  int flag = -1;
  if (sum % n == 0) flag = 0;
  if (flag == 0)
    cout << n << '\n';
  else
    cout << n - 1 << '\n';
  return 0;
}
