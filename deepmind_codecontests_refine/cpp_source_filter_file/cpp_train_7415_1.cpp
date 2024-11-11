#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr1[n];
  vector<int> arr2;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    if (arr1[i] > n - k) {
      arr2.push_back(i);
      max += arr1[i];
    }
  }
  sort(arr2.begin(), arr2.end());
  cout << max << ' ';
  long long num = 1;
  for (int i = 1; i < arr2.size(); i++) {
    num *= (arr2[i] - arr2[i - 1]);
    num = num % 998244353;
  }
  cout << num;
}
