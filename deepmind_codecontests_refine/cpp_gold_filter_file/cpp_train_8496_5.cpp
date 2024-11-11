#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[n];
  int d[n];
  unsigned long long perday;
  for (int i = 0; i < n; ++i) cin >> s[i] >> d[i];
  perday = s[0];
  for (int i = 1; i < n; ++i) {
    if (s[i] > perday) {
      perday = s[i];
      continue;
    }
    for (int j = 1; 1; ++j)
      if ((s[i] + d[i] * j) > perday) {
        perday = s[i] + d[i] * j;
        break;
      }
  }
  cout << perday;
  return 0;
}
