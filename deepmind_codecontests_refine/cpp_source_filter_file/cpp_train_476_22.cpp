#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int time1 = t1 + s * v1 + t1;
  int time2 = t2 + s * v2 + t2;
  if (time1 > time2) {
    cout << "Second";
  } else if (time1 < time2) {
    cout << "First";
  } else {
    cout << "FriendShip";
  }
  return 0;
}
