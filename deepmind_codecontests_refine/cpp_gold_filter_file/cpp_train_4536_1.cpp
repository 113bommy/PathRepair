#include <bits/stdc++.h>
using namespace std;
int A[200005] = {};
int main() {
  int a;
  while (cin >> a) {
    for (int i = 1; i <= a; i++) {
      cin >> A[i];
      if (A[i] == 0) continue;
      A[i] %= 2;
      if (A[i] == 0) A[i] = 2;
    }
    int no = 0;
    for (int i = a; i >= 0; i--) {
      if (A[i] == 0) continue;
      if (A[i] == 1) {
        A[i]--;
        A[i - 1]--;
      } else if (A[i] == 2) {
        A[i] = 0;
      } else {
        no = 1;
      }
    }
    if (no)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
