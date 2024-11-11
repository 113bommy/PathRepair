#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  long long sum = 0;
  long long maxVal = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    maxVal = max(maxVal, arr[i]);
    sum += arr[i];
  }
  if (sum % 2) {
    cout << "NO\n";
  } else {
    if (maxVal <= sum - maxVal)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
