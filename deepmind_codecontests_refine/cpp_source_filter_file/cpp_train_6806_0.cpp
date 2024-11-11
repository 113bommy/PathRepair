#include <bits/stdc++.h>
using namespace std;
int n;
int a[100050];
int main() {
  istream& in = cin;
  in >> n;
  for (int i = 0; i < n; i++) {
    in >> a[i];
  }
  int bits[30];
  memset(bits, 0, sizeof(bits));
  for (int i = 0; i < 30; i++) {
    int b = 1 << i;
    for (int j = 0; j < n; j++) {
      bits[i] += ((a[j] & b) != 0);
    }
  }
  int m = 0;
  int msb = 0;
  for (int i = 29; i >= 0; i--) {
    if (bits[i] == n) {
      m |= (1 << i);
    } else if (bits[i] != 0) {
      msb = 1 << i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] -= m;
  }
  int res = 0;
  for (int i = 0; i < n;) {
    if (a[i] & msb) {
      int first = a[i];
      int j = i - 1;
      int second = 0;
      for (; j >= 0 && (a[j] & msb) == 0; j--) {
        if (a[j] > second) {
          second = a[j];
          res = max(res, first ^ second);
        }
      }
      j = i + 1;
      second = 0;
      for (; j < n && (a[j] & msb) == 0; j++) {
        if (a[j] > second) {
          second = a[j];
          res = max(res, first ^ second);
        }
      }
      i = j;
    } else {
      i++;
    }
  }
  cout << res << endl;
}
