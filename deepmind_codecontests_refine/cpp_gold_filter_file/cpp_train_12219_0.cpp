#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, s[10] = {}, mx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    s[i % 3] += a;
  }
  mx = max(s[0], max(s[1], s[2]));
  if (mx == s[0]) cout << "back";
  if (mx == s[1]) cout << "chest";
  if (mx == s[2]) cout << "biceps";
}
