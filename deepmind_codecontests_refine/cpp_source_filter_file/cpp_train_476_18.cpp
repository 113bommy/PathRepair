#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  long long t = 1;
  while (t--) {
    long long s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if (t1 * 2 + s * v1 > t2 * 2 + s * v2) {
      cout << "First";
    }
    if (t1 * 2 + s * v1 < t2 * 2 + s * v2) {
      cout << "Second";
    }
    if (t1 * 2 + s * v1 == t2 * 2 + s * v2) {
      cout << "Friendship";
    }
  }
  return 0;
}
