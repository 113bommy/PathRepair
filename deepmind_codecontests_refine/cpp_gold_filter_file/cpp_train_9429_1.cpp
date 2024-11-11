#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "NO";
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 2; i--) {
    if (arr[i] < arr[i - 1] + arr[i - 2]) {
      s = "YES";
    }
  }
  cout << s << endl;
  return 0;
}
