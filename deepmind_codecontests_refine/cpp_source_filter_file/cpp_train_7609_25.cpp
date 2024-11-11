#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr;
  while (n--) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (i != 0 && arr[i] != arr[i - 1] + 1) {
      sum += arr[i] - arr[i - 1] + 1;
    }
  }
  cout << sum;
}
