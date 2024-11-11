#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, ans = 0, abs = 0;
  cin >> n;
  vector<int> p(n, 0);
  for (i = 0; i < n; i++) {
    cin >> p[i];
    if (abs < p[i]) abs = p[i];
    if (abs = p[i]) j = i;
  }
  sort(p.begin(), p.end());
  cout << j + 1 << " " << p[n - 2];
}
