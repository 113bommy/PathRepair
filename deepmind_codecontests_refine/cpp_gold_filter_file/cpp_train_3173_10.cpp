#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  int arr[n], p[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    p[i] = arr[i];
  }
  sort(arr, arr + n);
  if (k < arr[n - 1] - arr[0]) {
    cout << "NO";
    return 0;
  }
  vector<int> v;
  for (int i = 0; i < arr[0] + 1; i++) {
    v.push_back(k);
  }
  for (int i = arr[0] + 2; i <= arr[n - 1]; i++) {
    k--;
    v.push_back(k);
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p[i]; j++) {
      cout << v[j] << " ";
    }
    cout << endl;
  }
}
