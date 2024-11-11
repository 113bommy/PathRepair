#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long dem = 0, i;
  for (i = 1; i <= a; i++) {
    if (b % i == 0 && b / i < a) dem++;
  }
  cout << dem;
}
