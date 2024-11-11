#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e17;
int main() {
  long long i, j, a, b, c, d, n, m, t;
  cin >> t;
  for (int zz = 1; zz <= t; zz++) {
    cin >> n;
    vector<long long> vec(n);
    for (i = 0; i < n; i++) {
      cin >> vec[i];
    }
    long long tem1 = 0, tem2 = 0;
    sort(vec.begin(), vec.end());
    long long tem = 0;
    for (i = 0; i < n; i++) {
      if (tem == vec[i]) {
        vec[i] = 500;
        tem++;
        continue;
      } else if (tem > vec[i]) {
        continue;
      } else {
        break;
      }
    }
    sort(vec.begin(), vec.end());
    tem1 = tem;
    tem = 0;
    for (i = 0; i < n; i++) {
      if (tem == vec[i]) {
        vec[i] = 1000;
        tem++;
        continue;
      } else if (tem < vec[i]) {
        continue;
      } else {
        break;
      }
    }
    tem2 = tem;
    cout << tem1 + tem2 << "\n";
  }
  return 0;
}
