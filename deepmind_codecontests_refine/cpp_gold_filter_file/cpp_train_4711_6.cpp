#include <bits/stdc++.h>
using namespace std;
int honest_coach(vector<int> arr, int n) {
  sort(arr.begin(), arr.end());
  int result = INT_MAX;
  for (int i = 0; i < arr.size() - 1; i++) {
    result = min(result, abs(arr[i] - arr[i + 1]));
  }
  return result;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << honest_coach(arr, n) << "\n";
  }
  return 0;
}
