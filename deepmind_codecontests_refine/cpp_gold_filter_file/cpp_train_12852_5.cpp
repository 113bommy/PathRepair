#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, sum = 0, m;
  vector<int> ele;
  cin >> n >> k;
  long long int b[n];
  for (int i = 0; i < n; i++) {
    cin >> m;
    ele.push_back(m);
  }
  sort(ele.begin(), ele.end());
  for (int i = 0; i < n; i++) {
    b[i] = ele[n - i - 1];
  }
  for (int i = 0; i < n + k - 1; i++) {
    if ((i + 1) % k == 0) {
      sum += ((b[i + 1 - k] - 1) * 2);
    }
  }
  cout << sum << endl;
  return 0;
}
