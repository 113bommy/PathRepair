#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, z;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  bool flag = false;
  for (long long int i = 0; i < n - 2; i++) {
    if (a[i] + a[i + 1] > a[i + 2]) flag = true;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
