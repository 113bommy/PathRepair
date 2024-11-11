#include <bits/stdc++.h>
using namespace std;
int NWD(int a, int b) {
  int c;
  while (b > 0) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int t[105];
int main() {
  int n, fufs;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  fufs = NWD(t[0], t[1]);
  for (int i = 2; i < n; i++) {
    fufs = NWD(fufs, t[i]);
  }
  sort(t, t + n);
  if ((t[n - 1] / fufs - n) % 2 == 0) {
    cout << "Bob";
  } else {
    cout << "Alice";
  }
  return 0;
}
