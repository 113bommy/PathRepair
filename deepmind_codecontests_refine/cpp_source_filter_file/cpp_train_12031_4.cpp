#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
long long x[N][4];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  long long result = 0;
  vector<long long> a;
  for (int i = 0; i < n; ++i) {
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 + b1 >= b1 + b2) {
      a.push_back(a1 + b1);
      a.push_back(a2 + b2);
      result += a1;
      result += a2;
      result -= b1;
      result -= b2;
    } else {
      if (a1 - b2 >= 0) {
        result += a1 - b2;
        result += a1 - b2;
      }
      if (b1 - a2 >= 0) {
        result -= b2 - a1;
        result -= b2 - a1;
      }
    }
  }
  sort(a.rbegin(), a.rend());
  int mul = 1;
  for (auto& x : a) {
    result += mul * x;
    mul *= -1;
  }
  cout << result / 2 << endl;
  return 0;
}
