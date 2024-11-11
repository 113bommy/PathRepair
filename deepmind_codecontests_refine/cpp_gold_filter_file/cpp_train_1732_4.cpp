#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, i, p, u, oc, lc;
  int m[1001];
  int left, right;
  bool seek;
  string moves = "";
  cin >> n;
  m[0] = 0;
  left = n;
  right = 0;
  for (i = 1; i <= n; i++) {
    cin >> m[i];
    if ((i < left) && (m[i] > 0)) left = i;
    if ((i > right) && (m[i] > 0)) right = i;
  }
  p = -1;
  while (right > 0) {
    for (i = p + 2; (i <= right) && (m[i] == 0); i++) {
      moves += "AR";
      p++;
    }
    oc = 1;
    lc = 0;
    seek = true;
    for (i = p + 2; i <= right; i++) {
      if (m[i] > 0) {
        oc += 4;
        if (seek) lc++;
      } else {
        oc--;
        seek = false;
      }
      if (oc <= 0) {
        u = lc;
        for (i = 0; i < u; i++) moves += "AR";
        moves += "A";
        for (i = 0; i < u; i++) moves += "L";
        moves += "A";
        for (i = p + 2; i < (p + 2 + lc); i++)
          if (m[i] > 0) m[i]--;
        break;
      }
    }
    if (oc > 0) {
      u = ((right - 1) - p);
      for (i = 0; i < u; i++) moves += "AR";
      moves += "AL";
      p = right - 2;
      if (m[right] == 1) {
        while ((m[p + 1] <= 1) && ((p + 1) >= left)) {
          p--;
          moves += "L";
        }
      }
      while ((m[p + 1] > 1) && ((p + 1) >= left)) {
        p--;
        moves += "L";
      }
      moves += "A";
      for (i = p + 2; i <= right; i++)
        if (m[i] > 0) m[i]--;
    }
    left = n;
    right = 0;
    for (i = 1; i <= n; i++) {
      if ((i < left) && (m[i] > 0)) left = i;
      if ((i > right) && (m[i] > 0)) right = i;
    }
  }
  cout << moves;
  return 0;
}
