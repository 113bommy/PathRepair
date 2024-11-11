#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int x = (v1 * s) + 2 * t1;
  int y = (v2 * s) + 2 * t2;
  if (x > y)
    cout << "First";
  else if (x < y)
    cout << "Second";
  else
    cout << "Friendship";
}
