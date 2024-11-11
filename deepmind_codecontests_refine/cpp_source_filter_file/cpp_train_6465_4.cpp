#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[10000] = {};
  int x[10000];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    x[i - 1] = arr[i] - arr[i - 1];
  }
  vector<int> v;
  int count = 0;
  for (int i = 1; i < n; i++) {
    int j = 0;
    for (; j <= n - i; j++) {
      if (x[j] != x[j + i]) break;
    }
    if (j == n - i) {
      count++;
      v.push_back(i);
    }
  }
  cout << count + 1 << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << n;
  return 0;
}
