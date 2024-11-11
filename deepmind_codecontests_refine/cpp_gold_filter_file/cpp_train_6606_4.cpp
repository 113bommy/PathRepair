#include <bits/stdc++.h>
using namespace std;
int c(int n, int k) {
  if (k == n || k == 0) return 1;
  return c(n - 1, k) + c(n - 1, k - 1);
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, q = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == '+')
      a1++;
    else
      b1++;
  }
  for (int i = 0; i < s2.length(); i++) {
    if (s2[i] == '+')
      a2++;
    else if (s2[i] == '-')
      b2++;
    else
      q++;
  }
  if (q == 0) {
    int ans1 = a1 - b1;
    int ans2 = a2 - b2;
    if (ans1 == ans2) {
      cout << 1;
      return 0;
    } else {
      cout << 0;
      return 0;
    }
  }
  if (a2 > a1 || b2 > b1) {
    cout << 0;
    return 0;
  }
  int v = pow(2, q);
  int m = min(a1 - a2, b1 - b2);
  cout << setprecision(12) << double(c(q, m)) / v;
  return 0;
}
