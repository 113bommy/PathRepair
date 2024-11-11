#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int N = 1e6 + 5;
int main() {
  int n, i, x, s1 = 0, s2 = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    s1 += x;
  }
  for (i = 0; i < n; i++) {
    cin >> x;
    s2 += x;
  }
  if (s1 >= s2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
