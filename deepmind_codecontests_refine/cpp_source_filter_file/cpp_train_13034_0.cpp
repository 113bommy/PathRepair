#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n];
    long long xori = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      xori ^= arr[i];
      sum += arr[i];
    }
    cout << 2 << endl;
    cout << xori << " " << xori * sum << endl;
  }
}
