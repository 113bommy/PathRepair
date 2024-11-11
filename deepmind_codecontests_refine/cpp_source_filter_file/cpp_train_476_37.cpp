#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a1, a2;
  a1 = (2 * t1) + (s * v1);
  a2 = (2 * t2) + (s * v2);
  if (a1 > a2)
    cout << "First";
  else if (a1 == a2)
    cout << "Friendship";
  else
    cout << "Second";
}
