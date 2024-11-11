#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, b;
  cin >> n >> b;
  long long int arr[n];
  long long int i;
  for (i = 0; i <= n - 1; i++) {
    cin >> arr[i];
  }
  long long int odd = 0, even = 0;
  vector<long long int> v;
  for (i = 0; i <= n - 2; i++) {
    if (arr[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
    if (odd == even) {
      v.push_back(arr[i + 1] - arr[i]);
      odd = 0;
      even = 0;
    }
  }
  sort(v.begin(), v.end());
  long long int sum = 0;
  long long int count = 0;
  for (i = 0; i < v.size(); i++) {
    if (sum + v[i] <= b) {
      sum = sum + v[i];
      count++;
    }
  }
  cout << count << "\n";
  return 0;
}
