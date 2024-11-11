#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v1, v2, t1, t2, s, f;
  cin >> n >> v1 >> v2 >> t1 >> t2;
  f = 2 * t1 + n * v1;
  s = 2 * t2 + n * v2;
  if (f < s)
    cout << "First";
  else if (s < f)
    cout << "Second";
  else
    cout << "Friendship";
}
