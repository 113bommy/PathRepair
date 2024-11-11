#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
int two(int x) {
  int ans = 0;
  while (x > 0) {
    if (x % 2 == 0 && x != 1) {
      x = x / 2;
    } else if (x == 1) {
      ans = 1;
    } else if (x != 1) {
      ans = 0;
    }
  }
  if (ans)
    return 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int p[n + 1];
  for (int i = 1; i <= n; i++) {
    p[a[i]] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}
