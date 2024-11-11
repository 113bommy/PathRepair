#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  string s;
  cin >> s;
  int a[30] = {0};
  for (long long i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  for (long long i = 0; i < 26; i++) {
    if (a[i] % k != 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
