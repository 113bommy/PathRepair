#include <bits/stdc++.h>
using namespace std;
int a[100100], b[100100], m[100100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (b[a[i]] >= 1) {
      cout << 0 << endl;
      return 0;
    }
    b[a[i]]++;
  }
  long long c = -1;
  for (int i = 0; i < n; i++) {
    c = x & a[i];
    m[c]++;
    if (b[c] >= 1 && c != a[i]) {
      cout << 1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < 100100; i++) {
    if (m[i] >= 1) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
