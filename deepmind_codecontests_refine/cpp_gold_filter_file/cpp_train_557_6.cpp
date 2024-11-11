#include <bits/stdc++.h>
using namespace std;
int n;
int abs(int a) {
  if (a < 0) return -a;
  return a;
}
int main() {
  cin >> n;
  int i;
  int sum = 0;
  string sol = "";
  for (i = 1; i <= n; i++) {
    int a, g;
    cin >> a >> g;
    if (abs(sum - g) <= 500) {
      sum -= g;
      sol += 'G';
    } else {
      sum += a;
      sol += 'A';
    }
  }
  if (sum <= 500) {
    cout << sol;
  } else {
    cout << "-1";
  }
  return 0;
}
