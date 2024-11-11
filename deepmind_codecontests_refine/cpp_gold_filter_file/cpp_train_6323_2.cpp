#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int elem;
    cin >> elem;
    a.push_back(elem);
  }
  int count = 0;
  int l = 0;
  int r = a.size() - 1;
  while (l <= r) {
    if (a[l] <= k) {
      l++;
      count++;
    } else if (a[r] <= k) {
      r--;
      count++;
    } else
      break;
  }
  cout << count << endl;
}
