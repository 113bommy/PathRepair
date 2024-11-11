#include <bits/stdc++.h>
using namespace std;
int power(int a, int b) {
  int c = 1, i;
  for (i = 1; i <= b; i++) c *= a;
  return c;
}
int main() {
  int n, d, x, cnt = 0;
  cin >> n >> d;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] <= v[i - 1]) {
      int temp = abs(v[i] - v[i - 1]) / d + 1;
      cnt += temp;
      v[i] += (temp * d);
    }
  }
  cout << cnt << '\n';
  return 0;
}
