#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, nc, c1, start, end;
  short *seq, crim;
  cin >> n >> c;
  nc = n - c;
  c1 = c - 1;
  if (nc > c1) {
    start = 1;
    end = c + c1;
  } else {
    start = c - nc;
    end = n;
  }
  seq = new short[end - start + 1];
  int criminals = 0;
  for (int i = 1; i < start; i++) {
    cin >> crim;
    if (crim == 1) criminals++;
  }
  if (end != start) {
    for (int i = 0; i < end - start + 1; i++) {
      cin >> crim;
      seq[i] = crim;
    }
    for (int i = 0; i <= c1 - start; i++) {
      if (seq[i] == 1 && seq[end - i] == 1) criminals += 2;
    }
    if (seq[c1 - start + 1] == 1) criminals++;
  } else {
    cin >> crim;
    if (crim == 1) criminals++;
  }
  for (int i = end + 1; i <= n; i++) {
    cin >> crim;
    if (crim == 1) criminals++;
  }
  cout << criminals;
  return 0;
}
