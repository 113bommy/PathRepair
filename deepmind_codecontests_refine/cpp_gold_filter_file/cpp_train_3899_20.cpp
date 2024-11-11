#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  vector<int> p1(3002, 0), p2(3002, 0);
  int maxday = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    p2[a] += b;
    if (maxday < a) maxday = a;
  }
  long long ans = 0LL;
  for (int i = 1; i <= maxday; ++i) {
    int start = 0;
    start = min(p1[i], v);
    p1[i] = 0;
    ans += start;
    int x = 0;
    if (start < v) {
      x = min(v - start, p2[i]);
      ans = ans + x;
    }
    p1[i + 1] += p2[i] - x;
    p2[i] = 0;
  }
  ans = ans + min(p1[maxday + 1], v);
  cout << ans << endl;
  return 0;
}
