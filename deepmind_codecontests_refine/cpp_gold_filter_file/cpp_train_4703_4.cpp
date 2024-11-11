#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans[n];
  for (int i = 0; i < (int)n; i++) {
    int a, b;
    cin >> a >> b;
    ans[i] = 2 * b;
  }
  for (int i = 0; i < (int)n; i++) cout << ans[i] << endl;
  return 0;
}
