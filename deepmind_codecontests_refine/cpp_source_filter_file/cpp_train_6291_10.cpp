#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int mn = 1000000000;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < a[i]; j++) {
      int val;
      cin >> val;
      sum += val * 5;
    }
    sum += 15 * n;
    mn = min(mn, sum);
  }
  cout << mn << endl;
}
