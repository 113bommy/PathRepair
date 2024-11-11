#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int A[2] = {100001, 0};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    while (t > a) {
      a += b;
    }
    if (A[0] > a) {
      A[0] = a;
      A[1] = i + 1;
    }
  }
  printf("%d", A[1]);
}
