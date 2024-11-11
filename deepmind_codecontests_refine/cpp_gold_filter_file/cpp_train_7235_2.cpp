#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long sum = abs(arr[0]);
  for (long long i = 0; i < n - 1; i++) {
    sum += abs(arr[i + 1] - arr[i]);
  }
  cout << sum << " ";
}
