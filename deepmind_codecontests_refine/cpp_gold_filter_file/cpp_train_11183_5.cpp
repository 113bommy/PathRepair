#include <bits/stdc++.h>
using namespace std;
int acc[1002], s[1002];
int main() {
  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s[t]++;
  }
  for (int i = 1; i < 1002; i++) {
    acc[i] = acc[i - 1] + s[i];
  }
  int d;
  cin >> d;
  int total = 0;
  for (int i = d + 1; i < 1002; i++) {
    if (acc[i] - acc[i - d - 1] > total) total = acc[i] - acc[i - d - 1];
  }
  cout << total << endl;
  return 0;
}
