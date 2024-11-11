#include <bits/stdc++.h>
using namespace std;
bool check(int N) {
  if (N == 1) return false;
  for (int i = 2; i * i < N; i++) {
    if (N % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int i;
  if (check(n)) {
    cout << 1 << endl;
    printf("%d\n", n);
  } else if (n % 2 == 0) {
    if (n < 6) {
      cout << 2 << endl;
      printf("%d %d\n", 2, 2);
    } else {
      for (i = n - 2; i > 2; i--) {
        if (check(i) && check(n - 2 - i)) {
          break;
        }
      }
      if (n - 2 - i == 0) {
        cout << 2 << endl;
        printf("%d %d\n", 2, i);
      } else {
        cout << 3 << endl;
        printf("%d %d %d\n", 2, i, n - 2 - i);
      }
    }
  } else {
    for (i = n - 3; i > 2; i--) {
      if (check(i) && check(n - 3 - i)) {
        break;
      }
    }
    if (n - 3 - i == 0) {
      cout << 2 << endl;
      printf("%d %d\n", 3, i);
    } else {
      cout << 3 << endl;
      printf("%d %d %d\n", 3, i, n - 3 - i);
    }
  }
  return 0;
}
