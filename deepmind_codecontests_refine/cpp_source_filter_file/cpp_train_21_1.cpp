#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, l, r;
    cin >> n >> l >> r;
    long long int sum = 0;
    long long int start = 1;
    int done = 0;
    while (sum <= l) {
      sum += 2 * (n - start);
      start++;
      if (start > n) {
        cout << 1 << " " << endl;
        done = 1;
        break;
      }
    }
    if (done) continue;
    start--;
    sum -= 2 * (n - start);
    long long int next = start + 1;
    long long int cur = 0;
    for (long long int i = sum + 1; i <= r; i++) {
      if (i < l) {
        if (i % 2 == 0) next++;
      } else {
        if (i % 2 == 1)
          cout << start << " ";
        else {
          cout << next << " ";
          next++;
        }
      }
      cur++;
      if (cur == 2 * (n - start)) {
        cur = 0;
        start = start + 1;
        next = start + 1;
        if (start == n) start = 1;
      }
    }
    cout << endl;
  }
}
