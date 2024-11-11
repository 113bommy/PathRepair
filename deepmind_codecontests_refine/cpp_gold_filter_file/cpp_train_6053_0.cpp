#include <bits/stdc++.h>
using namespace std;
long long cnt1, cnt2, cnt3, cnt4;
int main() {
  cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
  if (cnt3 >= 1 && (cnt1 == 0 || cnt4 == 0))
    cout << 0;
  else if (cnt1 != cnt4)
    cout << 0;
  else
    cout << 1;
  return 0;
}
