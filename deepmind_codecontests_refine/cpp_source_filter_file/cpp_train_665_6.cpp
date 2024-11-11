#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int ser = 0;
  long long int dim = 0;
  auto it1 = v.begin();
  auto it2 = v.end();
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (*it1 > *it2) {
        ser = ser + *it1;
        it1++;
      } else {
        ser = ser + *it2;
        it2--;
      }
    }
    if (i % 2 != 0) {
      if (*it1 > *it2) {
        dim = dim + *it1;
        it1++;
      } else {
        dim = dim + *it2;
        it2--;
      }
    }
  }
  cout << ser << " " << dim;
  return 0;
}
