#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:133217728")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  long long s;
  long long ss = 0;
  int x[200200];
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    ss += x[i];
  }
  for (int i = 0; i < n; i++) {
    long long ans = max(0LL, x[i] + s - ss - 1) + max(0LL, x[i] + n - s - 1);
    cout << ans << " ";
  }
  return 0;
}
