#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, v;
  cin >> n >> v;
  long long int i, a, b, cnt = 0, t[3001] = {0};
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    t[a] += b;
  }
  long long int prev = 0;
  cnt = 0;
  for (i = 1; i < 3001; i++) {
    int t1 = t[i];
    if (t1 + prev <= v) {
      cnt = cnt + t1 + prev;
      prev = 0;
    } else {
      cnt = cnt + v;
      if (v < prev) {
        prev = t1;
      } else {
        prev = t1 - (v - prev);
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
