#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  char ch;
  int FL = 0, LL = 0, FR = 0, LR = 0, CL = 0, CR = 0;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    if (ch != '.') {
      if (ch == 'L') {
        CL++;
        if (FL == 0) {
          FL = i;
        }
        LL = i;
      } else {
        CR++;
        if (FR == 0) {
          FR = i;
        }
        LR = i;
      }
    }
  }
  if (CL == 0) {
    cout << LL << ' ' << FL - 1;
  } else if (CR == 0) {
    cout << FR << ' ' << LR + 1;
  } else {
    cout << FR << ' ' << LR;
  }
  return 0;
}
