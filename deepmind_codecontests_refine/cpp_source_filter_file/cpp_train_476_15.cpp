#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v1, v2, t1, t2;
  cin >> n >> v1 >> v2 >> t1 >> t2;
  int x = v1 * n + 2 * t1;
  int y = v2 * n + 2 * t2;
  if (x > y) {
    cout << "First";
    return 0;
  }
  if (y > x) {
    cout << "Second";
    return 0;
  }
  cout << "Friendship";
  return 0;
}
