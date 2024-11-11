#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N], b[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  a[n + 1] = -1;
  long long res = 0;
  int cur = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i + 1]) cur++;
    if (cur == 1 && a[i] == a[i + 1]) {
      if (a[i] == 0 || (i > 1 && a[i - 1] == a[i] - 1)) {
        cout << "cslnb" << '\n';
        return 0;
      }
      a[i]--;
      res++;
    }
  }
  if (cur > 1) {
    cout << "cslnb" << '\n';
    return 0;
  }
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    b[i] = cnt;
    if (a[i + 1] != cnt) cnt++;
  }
  for (int i = 1; i <= n; i++) {
    res += (a[i] - b[i]);
    res %= 2;
  }
  cout << (res & 1 ? "sjfnb" : "cslnb") << '\n';
  return 0;
}
