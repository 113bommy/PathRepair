#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 1, m1 = -1, m2 = -1;
  vector<long long> a(n + 5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > m1) {
      a[x]--;
      m2 = m1;
      m1 = x;
    } else if (x > m2) {
      a[m1]++;
      m2 = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[ans]) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
