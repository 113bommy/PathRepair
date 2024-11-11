#include <bits/stdc++.h>
using namespace std;
int main() {
  int tmp, prev = -1, t;
  int max = 0, tmpMax = 0;
  cin >> t;
  cin >> prev;
  for (int i = 1; i < t; i++) {
    cin >> tmp;
    if (tmp > prev)
      tmpMax++;
    else
      tmpMax = 0;
    if (tmpMax > max) max = tmpMax;
    prev = tmp;
  }
  cout << (max + 1) << endl;
  return 0;
}
