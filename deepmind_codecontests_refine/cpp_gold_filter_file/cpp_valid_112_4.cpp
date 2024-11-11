#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a[3], m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    long long mx = a[0] + a[1] + a[2] - 3;
    sort(a, a + 3);
    long long mn = 0;
    if (a[0] + a[1] + 1 < a[2]) mn = a[2] - a[0] - a[1] - 1;
    if (m > mx || m < mn)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
