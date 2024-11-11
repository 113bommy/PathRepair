#include <bits/stdc++.h>
using namespace std;
int n, k, i, v[2019], t;
bool desc(int a, int b) { return a < b; }
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n, desc);
  for (i = 0; i < n; i += k) t = t + 2 * v[i] - 2;
  cout << t;
  return 0;
}
