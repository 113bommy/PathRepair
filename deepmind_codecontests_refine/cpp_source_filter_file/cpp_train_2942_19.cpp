#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n == 1 ? 1 : n / 2) << '\n';
  }
}
