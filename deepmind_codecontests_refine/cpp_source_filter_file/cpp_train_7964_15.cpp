#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x] = i;
  }
  int res = 0;
  for (int i = 2; i <= n; i++) res += abs(a[i] - a[i - 1]);
  cout << res << endl;
  return 0;
}
