#include <bits/stdc++.h>
const int N = 1e5 + 7;
const long long INF = 1e9 + 7;
using namespace std;
int n, one, two;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == 1)
      ++one;
    else
      ++two;
  }
  if (one > two)
    cout << two - (one - two) / 3;
  else
    cout << one;
  return 0;
}
