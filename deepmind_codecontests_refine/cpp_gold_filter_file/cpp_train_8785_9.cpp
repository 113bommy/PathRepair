#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000], b[1000], n, t = 0;
  cin >> n;
  t = n * n;
  for (int i = 0; i < t / 2; i++) {
    cout << i + 1 << " " << (t)-i << endl;
  }
  return 0;
}
