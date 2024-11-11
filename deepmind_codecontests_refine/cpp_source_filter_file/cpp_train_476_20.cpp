#include <bits/stdc++.h>
using namespace std;
void KeyRaces(int s, int v1, int v2, int t1, int t2) {
  int i, cnt1 = 0, cnt2 = 0;
  cnt1 += t1 * 2;
  cnt2 += t2 * 2;
  for (i = 0; i < s; i++) {
    cnt1 += v1;
    cnt2 += v2;
  }
  if (cnt1 > cnt2) {
    cout << "First";
  }
  if (cnt1 < cnt2) {
    cout << "Second";
  }
  if (cnt1 == cnt2) {
    cout << "Friendship";
  }
}
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  KeyRaces(s, v1, v2, t1, t2);
}
