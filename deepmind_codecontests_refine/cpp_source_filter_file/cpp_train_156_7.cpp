#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<int> ids;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ids.push_back(t);
  }
  int last = 0;
  for (int i = 1; i <= n + 1; i++) {
    int t;
    long long ki = (long long)i * (i + 1) / 2;
    if (ki > k) {
      last = i - 1;
      break;
    }
  }
  k -= (long long)last * (last + 1) / 2;
  cout << ids[k - 1] << endl;
  return 0;
}
