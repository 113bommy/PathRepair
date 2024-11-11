#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 10;
int a[maxN], b[maxN], n, k, sum, i, j;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i + 1;
    j = i - 1;
    while (j >= 0 && a[j] > a[j + 1]) {
      swap(a[j], a[j + 1]);
      swap(b[j], b[j + 1]);
      j--;
    }
  }
  i = 0;
  while (i < n && sum + a[i] < k) sum += a[i++];
  cout << i << endl;
  for (j = 0; j < i; j++) cout << b[j] << ' ';
  return 0;
}
