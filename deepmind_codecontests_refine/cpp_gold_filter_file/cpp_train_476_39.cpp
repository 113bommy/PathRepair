#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  int first, second;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  first = s * v1 + 2 * t1;
  second = s * v2 + 2 * t2;
  if (first < second) {
    cout << "First";
  } else {
    if (first == second)
      cout << "Friendship";
    else
      cout << "Second";
  }
  return 0;
}
