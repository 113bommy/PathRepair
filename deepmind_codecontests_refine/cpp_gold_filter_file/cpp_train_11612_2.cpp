#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  long long lH, lH1, lA, lB;
  cin >> lH >> lH1 >> lA >> lB;
  if ((lH + 8 * lA) >= lH1)
    cout << 0 << endl;
  else if (lA > lB) {
    int iUp, iDown;
    iUp = lH1 - lH - (8 * lA);
    iDown = 12 * (lA - lB);
    cout << (iUp + iDown - 1) / iDown << endl;
  } else
    cout << -1 << endl;
  return 0;
}
