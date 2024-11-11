#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[n];
  for (int i = 0; i < n; ++i) cin >> s[i];
  sort(s, s + n);
  int i = 0, j = n / 2, ans = 0;
  while (i < n / 2 && j < n) {
    if (s[i] * 2 <= s[j]) {
      i++;
      j++;
      ans++;
    } else
      j++;
  }
  cout << n - i << endl;
  return 0;
}
