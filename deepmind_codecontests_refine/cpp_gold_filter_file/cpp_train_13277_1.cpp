#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int i, a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int ma = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > ma + 1) {
      a[i] = ma + 1;
    }
    ma = max(ma, a[i]);
  }
  cout << a[i - 1] + 1;
}
