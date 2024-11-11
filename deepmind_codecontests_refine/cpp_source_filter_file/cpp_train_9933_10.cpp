#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v, s1;
  int n, min = 10005, x, k, c = 0, s = 0;
  cin >> n >> k;
  s1.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    s += x;
    v.push_back(x);
    s1.push_back(s);
  }
  x = 0;
  for (int j = k; j <= n; j++) {
    if (s1[j] - s1[j - k] < min) {
      min = s1[j] - s1[j - k];
      x = j;
    }
  }
  cout << x - k + 1 << endl;
  return 0;
}
