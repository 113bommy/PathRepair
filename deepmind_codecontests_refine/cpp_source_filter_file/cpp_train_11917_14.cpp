#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, a[N];
int main() {
  cin >> n;
  a[1] = 1;
  for (int i = 1; i < N; i++) {
    a[i] = (i * (i + 1)) / 2;
    if (i > 2) a[i] += a[i - 1];
    if (a[i] > n) {
      cout << i - 1;
      return 0;
    }
  }
  return 0;
}
