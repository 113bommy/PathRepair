#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long sum = 0, sum2 = 0;
  cin >> n;
  long long arr[n], arr2[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> arr2[i];
  for (int i = 0; i < n; i++) {
    sum = sum | arr[i];
    sum2 = sum2 | arr2[i];
  }
  cout << sum + sum2;
  return 0;
}
