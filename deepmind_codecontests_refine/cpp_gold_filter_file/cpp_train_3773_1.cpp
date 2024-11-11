#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int mid = (n / 2);
    int start = mid - 1, end = mid;
    if (n % 2) {
      cout << a[mid] << ' ';
      end = mid + 1;
    }
    while (start >= 0) {
      cout << a[start--] << ' ' << a[end++] << ' ';
    }
    cout << endl;
  }
  return 0;
}
