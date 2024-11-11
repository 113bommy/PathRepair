#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6 + 3;
const int N = 1e3 + 1;
int main() {
  int n;
  cin >> n;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur = (cur + i) % n;
    cout << cur + 1 << ' ';
  }
  return 0;
}
