#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, d, y, cn = 0, one = 0, z = 0, mx = 10000000, mn = 0;
  cin >> a;
  long long int arr[a];
  long long int sum = 0;
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  vector<int> vec;
  b = a;
  for (int i = 0; i < a; i++) {
    if (sum % b == 0 && sum / b == arr[i]) {
      vec.push_back(arr[i]);
      b = b - 1;
      sum -= arr[i];
    }
  }
  cout << vec.size() << endl;
  if (vec.size() > 0) {
    for (int i = 0; i < vec.size() - 1; i++) cout << vec[i] << " ";
    cout << vec[vec.size() - 1] << endl;
  }
  return 0;
}
