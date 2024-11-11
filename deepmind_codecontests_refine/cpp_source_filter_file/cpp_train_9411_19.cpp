#include <bits/stdc++.h>
using namespace std;
int main() {
  int ca, cb, cc;
  cin >> ca >> cb >> cc;
  int minca = (ca < cc ? ca : cc);
  for (int i = 0; i <= minca; i++) {
    int rab = ca - i;
    int rbc = cc - i;
    int cnt = 0;
    if (rab == 0) cnt++;
    if (rbc == 0) cnt++;
    if (i == 0) cnt++;
    if (rab + rbc == cb && cnt >= 2) {
      cout << rab << ' ' << rbc << ' ' << i << endl;
      return 0;
    }
  }
  cout << "Impossible\n";
  return 0;
}
