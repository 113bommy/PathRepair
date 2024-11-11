#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b, c;
  vector<long long> o;
  for (long long i = 0; i < 10; i++) {
    cout << i << i << i << i << endl;
    cin >> b >> c;
    if (b == 4) return 0;
    for (long long j = 0; j < b; j++) o.push_back(i);
  }
  for (long long i = 0; i < 4; i++) {
    for (long long j = 0; j < 4; j++) {
      for (long long k = 0; k < 4; k++) {
        for (long long l = 0; l < 4; l++) {
          if (i != j && i != k && i != l && k != l && j != l && j != k) {
            cout << o[i] << o[j] << o[k] << o[l] << endl;
            cin >> b >> c;
            if (b == 4) return 0;
          }
        }
      }
    }
  }
}
