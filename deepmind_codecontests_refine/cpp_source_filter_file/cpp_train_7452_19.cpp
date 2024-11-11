#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool div() {
  if (k == 1 && m > 1) return 1;
  for (int i = 2; i < sqrt(m); i++)
    if (m % i == 0) {
      if (k <= i || k <= m / i) return 1;
    }
  return 0;
}
int main() {
  cin >> n >> m >> k;
  if (n % 2 == 0)
    cout << "Marsel";
  else if (div())
    cout << "Timur";
  else
    cout << "Marsel";
}
