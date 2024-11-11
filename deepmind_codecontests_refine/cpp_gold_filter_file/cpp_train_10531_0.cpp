#include <bits/stdc++.h>
using namespace std;
void print(int n, int m) {
  if (n == m) {
    print(n - 1, m);
  } else if (n == 0) {
    return;
  } else {
    print(n - 1, m);
    cout << (1 << (n - 1)) << " ";
    print(n - 1, m);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int max = 1;
  while (m >>= 1) {
    max++;
  }
  if (max <= n)
    cout << (1 << n - 1) - 1 << endl;
  else
    cout << (((1 << n - 1) - 1) << 1) + 1 << endl;
  print(n, max);
}
