#include <bits/stdc++.h>
using namespace std;
long long k[10] = {9,      99,      999,      9999,      99999,
                   999999, 9999999, 99999999, 999999999, 9999999999};
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long A, B;
    cin >> A >> B;
    long long w = lower_bound(k, k + 10, B) - k + 1;
    cout << A * w << endl;
  }
}
