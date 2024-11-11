#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926536;
int main() {
  vector<long long> v;
  for (int i = 0; i <= 32; i++)
    for (int j = 0; j <= 19; j++) {
      long long d = pow(2, i);
      long long t = pow(3, j);
      v.push_back(d * t);
    }
  sort(v.begin(), v.end());
  int l, r;
  cin >> l >> r;
  int a1, a2;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > r) {
      a2 = i + 1;
      break;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > (l - 1)) {
      a1 = i + 1;
      break;
    }
  }
  cout << a2 - a1;
}
