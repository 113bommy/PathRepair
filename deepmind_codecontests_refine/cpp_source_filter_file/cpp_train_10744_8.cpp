#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    vector<long long> arr;
    arr.resize(n);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    if (arr[2] > arr[0] + arr[1] + 1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}
