#include <bits/stdc++.h>
using namespace std;
queue<int> op[40];
int main() {
  int n;
  cin >> n;
  int a[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = n - 1; i >= 0; i--) {
    int j;
    for (j = 20; j >= 0; j--) {
      if ((a[i] & (1 << j))) {
        if (op[j].size()) {
          int t = op[j].front();
          op[j].pop();
          a[t] |= (1 << j);
          a[i] -= (1 << j);
        }
      }
      if (!(a[i] & (1 << j))) {
        op[j].push(i);
      }
    }
  }
  long long sum = 0;
  for (i = 0; i < n; i++) sum += (a[i] * a[i]);
  cout << sum << endl;
  return 0;
}
