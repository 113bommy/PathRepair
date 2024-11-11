#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x[105];
int main() {
  cin >> n;
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    s1 += x[i];
    if (s1 > s2) swap(s1, s2);
  }
  cout << s1 << " " << s2;
  return 0;
}
