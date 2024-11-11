#include <bits/stdc++.h>
using namespace std;
int p[4096], q[4096], r[4096], input[4096];
int main() {
  int k, n, a = 0;
  cin >> k;
  n = 1 << k;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    p[i] = q[i] = r[i] = i;
    a ^= input[i];
  }
  if (a) {
    cout << "Fou\n";
    return 0;
  }
  for (int i = 0, j = 0; i < n; i++, j = i) {
    while (input[j] != (p[j] ^ q[j])) {
      int temp = input[j] ^ q[j];
      r[p[j]] = temp;
      r[p[temp]] = j;
      swap(p[temp], p[j]);
      if (temp > i) break;
      swap(q[temp], q[i + 1]);
      j = temp;
    }
  }
  cout << "Shi\n";
  for (int i = 0; i < n; i++) cout << p[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++) cout << q[i] << ' ';
  cout << '\n';
  return 0;
}
