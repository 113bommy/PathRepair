#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int64_t a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n - 2; i++) {
    if (a[i] + a[i + 1] > a[i + 2]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
