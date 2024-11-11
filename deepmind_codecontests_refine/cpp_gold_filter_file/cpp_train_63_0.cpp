#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, maxa = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (k % a == 0 && maxa < a) {
      maxa = a;
    }
  }
  cout << k / maxa;
}
