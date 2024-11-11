#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    long long second;
    cin >> second;
    a[second] = i;
  }
  long long ans = 0, first = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == i)
      ans++;
    else if (first == 0) {
      if (a[a[i]] == i) {
        ans = ans + 2;
        first = 1;
      }
    }
  }
  if (first || ans == n)
    cout << ans;
  else {
    cout << ans + 1;
  }
  return 0;
}
