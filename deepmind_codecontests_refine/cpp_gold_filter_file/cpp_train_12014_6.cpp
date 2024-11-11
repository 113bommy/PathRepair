#include <bits/stdc++.h>
using namespace std;
vector<int> v(10000001, 1);
const int n = 10000000;
void solve(int t) {
  v[0] = v[1] = false;
  for (int i = 2; i <= n; i++) {
    if (v[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) v[j] = false;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (v[i] == 1) {
      cout << i << " ";
      t--;
    }
    if (!t) break;
  }
}
int main() {
  int n;
  cin >> n;
  solve(n);
  return 0;
}
