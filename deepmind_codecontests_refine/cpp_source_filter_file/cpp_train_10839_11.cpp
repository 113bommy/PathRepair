#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    long int a, b, k;
    cin >> a >> b >> k;
    if (k % 2 == 0)
      cout << (a * (k / 2) - b * (k / 2)) << "\n";
    else {
      cout << (a + a * (k / 2) - b * (k / 2)) << "\n";
    }
  }
  return 0;
}
