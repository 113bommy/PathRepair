#include <bits/stdc++.h>
using namespace std;
int N;
string scan, str;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  char cur, oR[100];
  int count = 0, ind = 0, anch = 0, first, nos;
  oR[(int)'0'] = 1;
  oR[(int)'1'] = 2;
  cin >> scan;
  for (int i = 0; i < (int)scan.size(); i++) {
    if ((scan[i] == cur && count < 2) || scan[i] != cur) {
      str += scan[i], count++;
      if (cur != scan[i]) count = 1, cur = scan[i];
    }
  }
  str = scan;
  N = str.size();
  while (ind < N && ind < 2) {
    count = 1;
    first = nos = 0;
    for (int i = 0; i < ind; i++) first |= oR[(int)str[i]];
    for (int i = ind + 1; i <= N; i++) {
      nos |= oR[(int)str[i - 1]];
      if (nos == 3) {
        count++;
        nos = 0;
      }
    }
    if ((nos | first) != 3) count--;
    anch = max(count, anch);
    ind++;
  }
  printf("%d\n", anch);
  return 0;
}
