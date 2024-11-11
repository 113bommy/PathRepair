#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    long long int sum = arr[i] + ((arr[i] - 1) * arr[i]) / 2;
    for (int i = 0; pow(2, i) <= arr[i]; i++) {
      sum -= 2 * pow(2, i);
    }
    cout << sum << endl;
  }
  return 0;
}
