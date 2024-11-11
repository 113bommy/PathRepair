#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int arr[5];
  long long int sum = 0;
  for (long long int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  map<long long int, long long int> m;
  for (long long int i = 0; i < 5; i++) {
    m[arr[i]]++;
  }
  long long int maxi = INT_MIN;
  long long int a = 3, b = 2;
  map<long long int, long long int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second > 1) {
      long long int count = min(a, max(b, it->second));
      long long int x = it->first;
      if (x * count > maxi) {
        maxi = x * count;
      }
    }
  }
  cout << sum - maxi;
}
