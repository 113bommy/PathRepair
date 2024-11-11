#include <bits/stdc++.h>
using namespace std;
int add(long long int a);
int add(long long int a) {
  int min = 10;
  int max = 0;
  while (a > 0) {
    int d = a % 10;
    if (min > d) min = d;
    if (max < d) max = d;
    if (min == 0) return 0;
    a = a / 10;
  }
  return min * max;
}
int main() {
  int t;
  cin >> t;
  long long int a[t];
  long long int k[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i] >> k[i];
    k[i] = k[i] - 1;
    long long int num = a[i];
    while (k[i]) {
      int p = add(a[i]);
      if (p == 0) break;
      num = num + p;
      k[i]--;
    }
    cout << num << endl;
  }
}
