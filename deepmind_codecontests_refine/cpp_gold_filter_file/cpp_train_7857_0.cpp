#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[105];
  int a[105] = {1};
  for (int k = 1; k <= n; k++) cin >> s[k];
  for (int j = 1; j <= n; j++) {
    for (int i = j; i <= n; i++)
      if (s[j] == s[i]) a[j]++;
  }
  sort(a + 1, a + n + 1);
  cout << a[n];
  return 0;
}
