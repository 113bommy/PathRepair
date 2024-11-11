#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, t, s = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> t;
    s += t;
  }
  if (N == 1) {
    if (s == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    if (s >= N - 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
