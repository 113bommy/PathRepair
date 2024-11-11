#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if ((n & 1) == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", 2 * i % n);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", 3 * i % n);
  }
}
