#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (auto &x : a) cin >> x;
    ;
    long long l = -1;
    for (int i = 0; i < N - 1; i++) {
      if (abs(a[i + 1] - a[i]) >= 2) {
        l = i;
        break;
      }
    }
    if (l == -1)
      cout << "No" << endl;
    else
      cout << "Yes\n" << l + 1 << " " << l + 2 << endl;
  }
  return 0;
}
