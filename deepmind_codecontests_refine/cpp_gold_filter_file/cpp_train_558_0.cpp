#include <bits/stdc++.h>
using namespace std;
bool hasZero(int a) {
  if (a == 0) return true;
  while (a != 0) {
    if (a % 10 == 0) return true;
    a /= 10;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  vector<int> nums;
  bool a = false, b = false;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
    if (k == 0 || k == 100)
      nums.push_back(k);
    else if (!a && k > 0 && k < 10) {
      nums.push_back(k);
      a = true;
    } else if (!b && k >= 10 && k < 100 && k % 10 == 0) {
      nums.push_back(k);
      b = true;
    }
  }
  if (!a && !b) {
    for (int i = 0; i < n; i++)
      if (!b && arr[i] >= 10 && arr[i] < 100) {
        nums.push_back(arr[i]);
        b = true;
      }
  }
  cout << nums.size() << endl;
  for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
  cout << endl;
}
