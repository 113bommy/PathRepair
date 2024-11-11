#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int res1 = (s * v1) + (t1 * 2);
  int res2 = (s * v2) + (t2 * 2);
  if (res1 < res2) {
    cout << "First";
  }
  if (res1 > res2) {
    cout << "Second";
  }
  if (res1 == res2) {
    cout << "Friendship";
  }
  return 0;
}
