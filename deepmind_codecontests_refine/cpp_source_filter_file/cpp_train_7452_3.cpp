#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  int n, m;
  cin >> n >> m >> k;
  bool a = false;
  for (int i = 2; i < sqrt(float(m)); i++) {
    if (m % i == 0) {
      if (i >= k || (m / i) >= k) a = true;
    }
  }
  if (k == 1 && m > 1) a = true;
  if (a)
    cout << (((n % 2) == 0) ? "Marsel" : "Timur");
  else
    cout << "Marsel";
}
