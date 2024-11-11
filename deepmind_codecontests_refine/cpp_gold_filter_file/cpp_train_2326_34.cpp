#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += (d - arr[i]);
  }
  cout << sum << endl;
  return 0;
}
