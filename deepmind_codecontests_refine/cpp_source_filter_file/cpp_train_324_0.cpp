#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  vector<long long int> odd, even;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    } else {
      odd.push_back(a[i]);
    }
  }
  if (even.size() >= odd.size()) {
    if (even.size() == odd.size() || even.size() - odd.size() == 1) {
      cout << "0" << endl;
      return 0;
    } else {
      long long int k = even.size() - odd.size() - 1;
      sort(even.begin(), even.end());
      long long int sum = 0;
      for (long long int i = 0; i < k; i++) {
        sum += even[i];
      }
      cout << sum << endl;
      return 0;
    }
  } else {
    if (odd.size() - even.size() == 1) {
      cout << "0" << endl;
      return 0;
    } else {
      long long int k = odd.size() + 1 - even.size();
      sort(odd.begin(), odd.end());
      long long int sum = 0;
      for (long long int i = 0; i < k; i++) {
        sum += odd[i];
      }
      cout << sum << endl;
      return 0;
    }
  }
}
