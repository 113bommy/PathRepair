#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, sum = 1, flag = 0;
  cin >> n >> t;
  int a[n];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  while (sum < (t)) {
    sum = sum + a[sum];
  }
  if (sum == (t)) {
    cout << "YES";
  } else
    cout << "NO";
}
