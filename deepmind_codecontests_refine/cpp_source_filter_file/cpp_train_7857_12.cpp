#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[n];
  int a[105] = {1};
  for (int k = 1; k <= n; k++) cin >> s[k];
  for (int k = 1; k <= n; k++) {
    for (int i = k; i <= n; i++)
      if (s[k] == s[i]) a[k]++;
  }
  sort(a + 1, a + n + 1);
  cout << a[n];
  return 0;
}
