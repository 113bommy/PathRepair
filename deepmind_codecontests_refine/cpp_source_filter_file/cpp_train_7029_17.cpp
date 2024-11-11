#include <bits/stdc++.h>
using namespace std;
int srav(string s1, string s2) {
  int i = 1;
  int sum = 0;
  for (i = 0; i < 6; i++)
    if (s1[i] != s2[i]) sum++;
  return sum;
}
int main() {
  int n, min = 10000000;
  cin >> n;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int buf;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      buf = srav(a[i], a[j]);
      if (buf % 2 == 0) {
        buf = buf / 2 - 1;
      } else {
        buf /= 2;
      }
      if (buf < min) min = buf;
    }
  cout << min << endl;
  return 0;
}
