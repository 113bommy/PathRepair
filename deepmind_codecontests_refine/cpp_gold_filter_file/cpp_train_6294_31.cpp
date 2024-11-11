#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag[100];
  int t1 = 0, t2 = 0;
  for (int i = 0; i < 100; i++) {
    flag[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    string l1;
    cin >> l1;
    l1[1] == '>' ? flag[l1[0]]++ : flag[l1[2]]++;
  }
  (flag, flag + 100);
  for (int i = 0; i < 100; i++) {
    if (flag[i] == 1) {
      t1 = i;
    }
    if (flag[i] == 2) {
      t2 = i;
    }
  }
  if (t1 + t2 == 133) {
    cout << 'A' << char(t1) << char(t2);
  }
  if (t1 + t2 == 131) {
    cout << 'C' << char(t1) << char(t2);
  }
  if (t1 + t2 == 132) {
    cout << 'B' << char(t1) << char(t2);
  }
  if (t2 == 0) {
    cout << "Impossible" << endl;
  }
  return 0;
}
