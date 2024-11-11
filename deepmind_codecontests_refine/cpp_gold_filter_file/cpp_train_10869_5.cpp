#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r;
  vector<long long> a;
  cin >> r;
  for (int i = 0; i < r; i++) {
    long long aux;
    cin >> aux;
    a.push_back(aux);
  }
  a.push_back(a[0]);
  long long n = 0, m = 1;
  long long min = abs(a[0] - a[1]);
  for (int i = 1; i < r; i++) {
    if (abs(a[i] - a[i + 1]) < min) {
      n = i % r;
      m = (i + 1) % r;
      min = abs(a[i] - a[i + 1]);
    }
  }
  cout << n + 1 << " " << m + 1;
  return 0;
}
