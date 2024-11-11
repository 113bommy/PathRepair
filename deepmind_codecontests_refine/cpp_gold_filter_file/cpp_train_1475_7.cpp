#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int days = 0;
  vector<int> arr;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    arr.push_back(k);
  }
  sort(arr.begin(), arr.end());
  for (auto i = arr.begin(); i != arr.end(); i++) {
    if (*i > days) days++;
  }
  cout << days << endl;
  return 0;
}
