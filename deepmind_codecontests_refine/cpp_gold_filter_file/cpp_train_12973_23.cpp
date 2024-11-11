#include <bits/stdc++.h>
using namespace std;
long long a[1090016] = {0};
int main() {
  a[1] = 4;
  a[2] = 6;
  long long k = 2, i, j;
  long long val = 8;
  for (i = 3; i <= 1000000;) {
    for (j = i; j < i + k; j++) a[j] = val;
    val = 2 + val;
    i = j;
    for (; j < i + k; j++) a[j] = val;
    val = 2 + val;
    i = j;
    k++;
  }
  long long n;
  cin >> n;
  cout << a[n] << "\n";
  return 0;
}
