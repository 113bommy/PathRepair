#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a[107] = {1, 2, 4};
  cin >> n;
  for (int i = 3; i < n; i++) a[i] = a[i - 2] + i + 1;
  cout << a[n - 1];
  return 0;
}
