#include <bits/stdc++.h>
using namespace std;
void fact(long long q) {
  int g = 1;
  long long n = q;
  long long count = 0;
  long long k = 1;
  int flag = 0;
  long long i;
  for (i = 2; i * i <= n; i++) {
    while (q % i == 0) {
      flag = 1;
      q = q / i;
      count = count + 1;
      if (count <= 2) k = k * i;
    }
  }
  if (q % i == 0) count = count + 1;
  if (flag == 0) {
    cout << 1 << endl;
    cout << 0 << endl;
    return;
  }
  if (count > 2) {
    cout << 1 << endl;
    cout << k << endl;
    return;
  } else
    cout << 2 << endl;
}
int main() {
  long long q;
  cin >> q;
  fact(q);
  return 0;
}
