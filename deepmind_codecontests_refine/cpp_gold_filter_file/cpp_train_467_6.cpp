#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5005;
long double diff[SIZE];
long double pre[SIZE];
int main() {
  for (auto& x : diff) x = 0;
  for (auto& x : pre) x = 0;
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto& x : vec) cin >> x;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      diff[vec[j] - vec[i]]++;
    }
  }
  for (int i = 5000; i >= 0; i--) {
    pre[i] = pre[i + 1] + diff[i];
  }
  long double num = 0;
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= 5000; j++) {
      if (diff[i] > 0 && diff[j] > 0) {
        if (i + j <= 5000) {
          num += (diff[i] * diff[j] * pre[i + j + 1]);
        }
      }
    }
  }
  long double N = n;
  long double den = ((N) * (N - 1)) / 2.0;
  den = den * den * den;
  cout << setprecision(12) << num / den << '\n';
}
