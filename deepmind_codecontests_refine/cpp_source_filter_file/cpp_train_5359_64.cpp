#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, g;
  int hb, hg;
  cin >> b >> g;
  int arrb[b];
  int arrg[g];
  for (int i = 0; i < b; i++) {
    arrb[i] = 0;
  }
  for (int i = 0; i < g; i++) {
    arrg[i] = 0;
  }
  cin >> hb;
  for (int i = 0; i < hb; i++) {
    int tmp;
    cin >> tmp;
    arrb[tmp] = 1;
  }
  cin >> hg;
  for (int i = 0; i < hg; i++) {
    int tmp;
    cin >> tmp;
    arrg[tmp] = 1;
  }
  for (int i = 0; i < b * g + 1; i++) {
    int boy = i % b;
    int girl = i % g;
    if (arrb[boy] == 1 || arrg[girl] == 1) {
      arrb[boy] = 1;
      arrg[girl] = 1;
    }
  }
  bool flag1 = true;
  bool flag2 = true;
  for (int i = 0; i < b; i++) {
    if (arrb[i] == 0) {
      flag1 = false;
    }
  }
  for (int i = 0; i < g; i++) {
    if (arrg[i] == 0) {
      flag2 = false;
    }
  }
  if (flag1 && flag2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
