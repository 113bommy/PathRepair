#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  if ((p - k > 1) && (p != 1)) cout << "<< ";
  if (p - k >= 1)
    for (int i = p - k; i < p; i++) cout << i << " ";
  else
    for (int i = 1; i < p; i++) cout << i << " ";
  cout << "(" << p << ") ";
  if (p + k <= n)
    for (int i = p + 1; i <= p + k; i++) cout << i << " ";
  else
    for (int i = p + 1; i <= n; i++) cout << i << " ";
  if (p + k < n) cout << ">>";
  return 0;
}
