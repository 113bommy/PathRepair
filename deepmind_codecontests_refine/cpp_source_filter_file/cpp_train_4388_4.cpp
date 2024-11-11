#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long long> b(n), e(n);
  long long sa = 0, sb = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      sa += v[i];
      b[i] = sa;
    } else {
      sb += v[i];
      b[i] = sb;
    }
  }
  e[0] = sa;
  e[1] = sb;
  for (int i = 2; i < n; i++) {
    if (i % 2 == 0)
      e[i] = sa - b[i - 2];
    else
      e[i] = sb - b[i - 2];
  }
  for (int i = 0; i < n; i++) {
    long long A = 0, B = 0;
    if (i - 1 >= 0) A += b[i - 1];
    if (i - 2 >= 0) B += b[i - 2];
    if (i + 1 <= n - 1) B += e[i + 1];
    if (i + 2 <= n + 1) A += e[i + 2];
    if (A == B) {
      sum++;
    }
  }
  cout << sum;
}
