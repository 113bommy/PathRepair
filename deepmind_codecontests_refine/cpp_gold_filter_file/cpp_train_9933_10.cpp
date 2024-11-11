#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    if (i == 0)
      m[i] += f;
    else
      m[i] = m[i - 1] + f;
  }
  long p = 10000000000, h = 1;
  for (int i = 0; i + k - 1 < n; i++) {
    if (i == 0) {
      if (m[i + k - 1] < p) {
        p = m[i + k - 1];
        h = i + 1;
      }
    } else {
      if (m[i + k - 1] - m[i - 1] < p) {
        p = m[i + k - 1] - m[i - 1];
        h = i + 1;
      }
    }
  }
  cout << h;
  return 0;
}
