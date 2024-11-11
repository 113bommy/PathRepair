#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, diff;
  cin >> n >> a >> b;
  vector<long long int> v;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    v.push_back(arr[i]);
  }
  sort(v.begin(), v.end());
  diff = v[a + 1] - v[b - 1];
  if (diff < 0) {
    cout << "0" << endl;
  } else {
    cout << diff << endl;
  }
}
