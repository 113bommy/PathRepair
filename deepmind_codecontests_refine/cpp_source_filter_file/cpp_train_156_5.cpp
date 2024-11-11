#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, temp = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i;
  for (i = 1; i <= n; i++) {
    temp += i;
    if (temp > k) break;
  }
  int gap = temp - k;
  cout << a[i - gap - 1];
}
