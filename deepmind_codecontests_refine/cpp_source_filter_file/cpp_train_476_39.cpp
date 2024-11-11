#include <bits/stdc++.h>
using namespace std;
vector<int> b(10000);
int main() {
  ios_base::sync_with_stdio(false);
  int n, v1, v2, t1, t2;
  cin >> n >> v1 >> v2 >> t1 >> t2;
  if (v1 * n + 2 * t1 > v2 * n + 2 * t1) cout << "Second";
  if (v1 * n + 2 * t1 < v2 * n + 2 * t1) cout << "First";
  if (v1 * n + 2 * t1 == v2 * n + 2 * t1) cout << "Friendship";
  return 0;
}
