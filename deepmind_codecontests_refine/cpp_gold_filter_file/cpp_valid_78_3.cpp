#include <bits/stdc++.h>
using namespace std;
int solve(long long l, long long r) {
  long long a = (r - 1) / 2;
  if (l <= (a + 1)) {
    return a;
  } else {
    return r - l;
  }
}
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long l;
    long long r;
    cin >> l;
    cin >> r;
    long long a;
    a = solve(l, r);
    cout << a << endl;
  }
}
