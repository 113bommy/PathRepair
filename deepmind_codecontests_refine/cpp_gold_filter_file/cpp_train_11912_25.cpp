#include <bits/stdc++.h>
using namespace std;
string app[] = {"1869", "6891", "8196", "6981", "9168", "6819", "8691"};
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  int a[11] = {0};
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    a[s[i] - '0']++;
  }
  a[1]--;
  a[6]--, a[8]--, a[9]--;
  int rem = 0;
  for (int i = 1; i < 10; i++) {
    while (a[i] > 0) {
      cout << i;
      a[i]--;
      rem = (rem * 10 + i) % 7;
    }
  }
  cout << app[rem];
  while (a[0] > 0) cout << 0, a[0]--;
  cout << endl;
  return 0;
}
