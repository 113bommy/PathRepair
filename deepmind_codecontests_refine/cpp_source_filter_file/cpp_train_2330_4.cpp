#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, t;
long long v[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ;
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  int j = 0, mx = 0;
  long long act = 0;
  for (int i = 1; i <= n; ++i) {
    while (act + v[j + 1] <= t && j + 1 <= n) {
      act += v[j + 1];
      ++j;
    }
    mx = max(mx, j - i + 1);
    act -= v[j];
  }
  cout << mx;
  return 0;
}
