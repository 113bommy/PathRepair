#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, k = 0, l = 0;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n; i++) {
    if (arr[i] == 4) a++;
    if (arr[i] == 8 and a > b) b++;
    if (arr[i] == 15 and b > c) c++;
    if (arr[i] == 16 and c > d) d++;
    if (arr[i] == 23 and d > e) e++;
    if (arr[i] == 42 and e > f) f++;
  }
  k = a + b + c + d + e + f;
  l = n - k + (k % 6);
  cout << l;
  return 0;
}
