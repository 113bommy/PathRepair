#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long a[n * 2];
  for (int i = 0; i < n * 2; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (a[n] == a[n - 1])
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
