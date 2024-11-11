#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string x, y, z;
  cin >> x >> y >> z;
  int64_t A = 0, B = 0, C = 0;
  char n = x[0], m = x[2], cmp = x[1];
  if (cmp == '>') {
    if (x[0] == 'A') {
      A++;
    } else if (x[0] == 'B') {
      B++;
    } else {
      C++;
    }
  } else {
    if (x[2] == 'A') {
      A++;
    } else if (x[2] == 'B') {
      B++;
    } else {
      C++;
    }
  }
  n = y[0], m = y[2], cmp = y[1];
  if (cmp == '>') {
    if (y[0] == 'A') {
      A++;
    } else if (y[0] == 'B') {
      B++;
    } else {
      C++;
    }
  } else {
    if (y[2] == 'A') {
      A++;
    } else if (y[2] == 'B') {
      B++;
    } else {
      C++;
    }
  }
  n = z[0], m = z[2], cmp = z[1];
  if (cmp == '>') {
    if (z[0] == 'A') {
      A++;
    } else if (z[0] == 'B') {
      B++;
    } else {
      C++;
    }
  } else {
    if (z[2] == 'A') {
      A++;
    } else if (z[2] == 'B') {
      B++;
    } else {
      C++;
    }
  }
  if (A == B || B == C || C == A) {
    cout << "Impossible"
         << "\n";
  } else if (A > B and A > C) {
    if (B > C) {
      cout << "CB";
    } else {
      cout << "BC";
    }
    cout << "A"
         << " ";
  } else if (A < B and B > C) {
    if (A > C) {
      cout << "CA";
    } else {
      cout << "AC";
    }
    cout << "B"
         << " ";
  } else {
    if (A > B) {
      cout << "B"
           << "A";
    } else {
      cout << "AB";
    }
    cout << "C";
  }
  return 0;
}
