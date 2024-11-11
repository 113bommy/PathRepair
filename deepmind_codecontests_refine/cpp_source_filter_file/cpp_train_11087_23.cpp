#include <bits/stdc++.h>
using namespace std;
int a[100020];
long long b[100020];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long max = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < max)
      b[i] = max - a[i] + 1;
    else
      max = a[i];
  }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
}
