#include <bits/stdc++.h>
using namespace std;
long long arr[10000001];
int main() {
  long long d = 1;
  arr[0] = 0;
  for (int i = 1; i < 10000001; i++) {
    arr[i] = arr[i - 1] + d;
    d += 2;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0 && k % 2 != 0) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 != 0 && k % 2 == 0) {
      cout << "NO" << endl;
      continue;
    }
    long long x = arr[k];
    if (n >= x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
