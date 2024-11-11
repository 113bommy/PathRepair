#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ints(n);
  for (int i = 1; i <= ints.size(); ++i) {
    cin >> ints[i - 1];
  }
  sort(ints.begin(), ints.end());
  int cnt = 0;
  for (int i = 1; i <= ints.size(); ++i) {
    if (ints[i] - ints[i - 1] > 1) {
      cnt += ints[i] - ints[i - 1] - 1;
    }
  }
  cout << cnt << "\n";
  return 0;
}
