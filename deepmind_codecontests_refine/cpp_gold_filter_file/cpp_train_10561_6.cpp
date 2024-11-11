#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, n3, t1, t2, t3;
  int k;
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  int a[10001] = {0};
  int b[10001] = {0};
  int c[10001] = {0};
  for (int i = 0; i < k; i++) {
    if (i + n1 < k) {
      a[i + n1] = a[i] + t1;
    }
  }
  for (int i = 0; i < k; i++) {
    b[i] = max(b[i], a[i] + t1);
    if (i + n2 < k) {
      b[i + n2] = b[i] + t2;
    }
  }
  for (int i = 0; i < k; i++) {
    c[i] = max(c[i], b[i] + t2);
    if (i + n3 < k) {
      c[i + n3] = c[i] + t3;
    }
  }
  cout << c[k - 1] + t3 << endl;
}
