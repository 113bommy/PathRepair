#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, len, need, place;
long long l[100100], ans[100100];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i];
    sum = sum + l[i];
  }
  for (int i = 1; i <= m; i++) {
    if (n - l[i] < i - 1) {
      cout << -1;
      return 0;
    }
  }
  if (sum < n) {
    cout << -1;
    return 0;
  }
  len = m + l[m] - 1;
  need = n - len;
  place = n - l[m] + 1;
  for (int i = m; i >= 1; i--) {
    ans[i] = place;
    if (need == 0) {
      place--;
    } else {
      place = place - (min(l[i - 1] - 1, need) + 1);
      need = need - l[i - 1] - 1;
      if (need < 0) need = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " ";
  }
}
