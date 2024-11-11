#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b = 0, sum = 0, q;
  for (int i = 0; i < n; i++) {
    cin >> q;
    if (q == -1 && sum == 0) b++;
    if (q == -1 && sum != 0) sum--;
    if (q >= 0) sum++;
  }
  cout << b;
  return 0;
}
