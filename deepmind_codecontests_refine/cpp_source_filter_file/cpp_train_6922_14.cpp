#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long k, l;
  cin >> k >> l;
  long long a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[k] < b[n - l]) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
