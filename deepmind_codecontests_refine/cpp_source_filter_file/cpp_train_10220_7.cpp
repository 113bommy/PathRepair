#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long int> start(n);
    vector<long long int> end(n);
    for (long long int i = 0; i < n; i++) {
      long long int min = v[i] - k;
      min = min > 0 ? min : 0;
      start[i] = min;
      end[i] = v[i] + k;
    }
    long long int sr = start[0];
    long long int er = end[0];
    long long int flag = 0;
    for (long long int i = 0; i < n; i++) {
      if (start[i] >= sr) {
        sr = start[i];
      }
      if (er < sr) {
        cout << "-1" << endl;
        flag = 1;
        break;
      }
      if (end[i] <= er) {
        er = end[i];
      }
      if (er < sr) {
        cout << "-1" << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    cout << sr << endl;
  }
  return 0;
}
