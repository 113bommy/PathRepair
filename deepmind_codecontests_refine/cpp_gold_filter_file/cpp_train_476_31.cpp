#include <bits/stdc++.h>
using namespace std;
const long double pi = 2 * acos(0.0);
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int ans, ans1;
  ans = s * v1 + 2 * t1;
  ans1 = s * v2 + 2 * t2;
  if (ans == ans1) cout << "Friendship";
  if (ans > ans1)
    cout << "Second";
  else if (ans < ans1)
    cout << "First";
}
