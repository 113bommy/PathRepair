#include <bits/stdc++.h>
using namespace std;
int main() {
  int mina[9] = {10};
  int minb[9] = {10};
  int maxa[9] = {0};
  int maxb[9] = {0};
  for (int i = 1; i < 9; i++) {
    mina[i] = 10;
    minb[i] = 10;
    maxa[i] = 0;
    maxb[i] = 0;
  }
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      char c;
      cin >> c;
      if (c == '.') continue;
      if (c == 'B') {
        minb[j] = min(minb[j], i);
        maxb[j] = max(maxb[j], i);
        continue;
      }
      if (c == 'W') {
        mina[j] = min(mina[j], i);
        maxa[j] = max(maxa[j], i);
        continue;
      }
    }
  }
  int ansa = INT_MAX;
  int ansb = INT_MAX;
  for (int i = 1; i < 9; i++) {
    if (maxb[i] != 0) {
      if (maxb[i] > maxa[i]) {
        ansb = min(ansb, 8 - maxb[i]);
      }
    }
    if (mina[i] != 10) {
      if (mina[i] < minb[i]) {
        ansa = min(ansa, 8 - mina[i]);
      }
    }
  }
  if (ansa <= ansb) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
