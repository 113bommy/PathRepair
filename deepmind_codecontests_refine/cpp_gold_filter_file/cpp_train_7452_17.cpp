#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int abc() {
  int i = 0, t = 0, r = int(sqrt(m)) + 1;
  while (++i < r && t < 2)
    if (m % i == 0) t++;
  if ((t > 1 && (m / (i - 1) >= k)) || (k == 1 && m != 1))
    return n % 2;
  else
    return 0;
}
int main() {
  cin >> n >> m >> k;
  if (abc())
    cout << "Timur";
  else
    cout << "Marsel";
  return 0;
}
