#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[k];
  int count = 0;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  while (n--) {
    int b;
    for (int i = 0; i < m; i++) {
      cin >> b;
      int *p = find(a, a + k, b);
      count = count + p - a + 1;
      for (int j = p - a; j > 0; j--) {
        int t = a[j];
        a[j] = a[j - 1];
        a[j - i] = t;
      }
    }
  }
  cout << count << endl;
  return 0;
}
