#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int A[] = {8, 2, 5, 5, 4, 5, 6, 3, 9, 8};
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    int k = i;
    while (k) {
      ans += A[k % 10];
      k /= 10;
    }
  }
  cout << ans;
  return 0;
}
