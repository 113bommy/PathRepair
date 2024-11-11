#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int a[N];
int n, cnt;
int main() {
  cin >> n;
  cin >> a[0];
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    sort(a, a + i);
    if (a[i] < a[0] || a[i] > a[i - 1]) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
