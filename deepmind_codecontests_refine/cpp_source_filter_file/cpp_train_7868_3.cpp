#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  unordered_map<long long int, int> left, right;
  long long int arr[n], sum = 0, tmp = 0;
  for (long long int i = 0; i < n; i++)
    cin >> arr[i], sum += arr[i], right[arr[i]]++;
  if (sum & 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (long long int i = 0; i < n; i++) {
    tmp += arr[i];
    left[arr[i]]++;
    right[arr[i]]--;
    if (tmp == sum / 2) {
      cout << "YES1" << endl;
      return 0;
    } else if (tmp > sum / 2) {
      if (left[tmp - sum / 2]) {
        cout << "YES2" << endl;
        return 0;
      }
    } else {
      if (right[sum / 2 - tmp]) {
        cout << "YES3" << i << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
