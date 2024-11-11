#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) cin >> d[i];
  vector<int> cpy(d);
  sort(d.begin(), d.end());
  int x = 0;
  int count = 0;
  for (int i = 0; i < d.size(); ++i) {
    if (x + d[i] <= k) {
      x += d[i];
      count++;
    } else
      break;
  }
  cout << count << endl;
  for (int i = 0; i < count; ++i) {
    for (int j = 0; j < d.size(); ++j) {
      if (d[i] == cpy[j]) {
        cout << j + 1 << " ";
        cpy[j] = 0;
        break;
      }
    }
  }
  return 0;
}
