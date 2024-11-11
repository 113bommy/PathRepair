#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int s = arr[0];
  for (long long int i = 1; i < n; i++) {
    arr[i] = s + arr[i];
    s = arr[i];
  }
  long long int q;
  cin >> q;
  vector<long long int> v;
  for (long long int i = 0; i < q; i++) {
    long long int l, r, sum = 0;
    cin >> l >> r;
    if (l == 1) {
      sum = arr[r - 1];
    } else {
      sum = arr[r - 1] - arr[l - 1];
    }
    v.push_back(sum / 10);
  }
  for (long long int i = 0; i < q; i++) {
    cout << v[i] << endl;
  }
}
