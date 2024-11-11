#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long int> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  int cases;
  cin >> cases;
  while (cases--) {
    long long int a, b;
    cin >> a >> b;
    cout << (arr[b] - arr[a]) / 10 << endl;
  }
  return 0;
}
