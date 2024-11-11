#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, inputt, x = 0, bigger = 0, stand = 0, index = 0, capcatiy = 0;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> inputt;
    if (inputt <= n) {
      x = n / inputt;
      bigger = x * inputt;
      if (bigger > stand) {
        stand = bigger;
        index = i;
        capcatiy = x;
      }
    }
  }
  cout << index + 1 << " " << capcatiy << endl;
  return 0;
}
