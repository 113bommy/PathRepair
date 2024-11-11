#include <bits/stdc++.h>
using namespace std;
void count(int n, int m, int k) {
  int a[m + 1], xors, friend_count = 0;
  for (int i = 0; i < m + 1; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    xors = a[i] ^ a[m];
    int count = 0;
    while (xors > 0) {
      xors = xors & (xors - 1);
      count++;
    }
    if (count <= k) friend_count++;
  }
  cout << friend_count;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  count(n, m, k);
  return 0;
}
