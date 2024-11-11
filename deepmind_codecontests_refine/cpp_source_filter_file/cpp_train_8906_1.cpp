#include <bits/stdc++.h>
using namespace std;
long long mx = 1e18, j = 0;
long long a[12345];
void pre() {
  a[1] = 2;
  a[2] = 3;
  j = 0;
  for (long long i = 3;; i++) {
    a[i] = a[i - 1] + a[i - 2];
    j++;
    if (a[i] > mx) break;
  }
}
int main() {
  pre();
  long long n, i;
  cin >> n;
  for (i = 0; i < j; i++) {
    if (a[i] > n) break;
  }
  cout << i - 1;
}
