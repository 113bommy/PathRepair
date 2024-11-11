#include <bits/stdc++.h>
using namespace std;
int fena[100005], fenn;
void initfen() { memset(fena, 0, sizeof(fena)); }
int fengetmax(int inx) {
  int ret = 0;
  for (int i = inx; i > 0; i -= (i & (-i))) ret = max(ret, fena[i]);
  return ret;
}
void fenset(int inx, int val) {
  for (int i = inx; i <= fenn; i += (i & (-i))) fena[i] = max(fena[i], val);
}
void doit() {
  int tn, ret, cmax;
  cin >> fenn;
  initfen();
  for (int i = 0; i < fenn; i++) {
    cin >> tn;
    cmax = fengetmax(tn);
    fenset(tn, cmax + 1);
    ret = max(ret, cmax + 1);
  }
  cout << ret << endl;
  return;
}
int main() {
  doit();
  return 0;
}
