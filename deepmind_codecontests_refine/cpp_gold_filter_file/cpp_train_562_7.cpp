#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, val, p, q, temp, seg;
  cin >> a >> b;
  val = a * a - b * b;
  seg = 1;
  for (long long i = 1; i <= min(a, b - 1); i++) {
    p = b % (i + 1);
    q = b / (i + 1);
    temp = i - 1 + (a - i + 1) * (a - i + 1) - p * (q + 1) * (q + 1) -
           (i + 1 - p) * q * q;
    if (val < temp) {
      val = temp;
      seg = i + 1;
    }
  }
  cout << val << endl;
  if (seg == 1) {
    for (long long i = 0; i < a; i++) {
      cout << "o";
    }
    for (long long i = 0; i < b; i++) {
      cout << "x";
    }
    cout << endl;
  } else {
    p = b % seg;
    q = b / seg;
    for (long long i = 0; i < q; i++) {
      cout << "x";
    }
    if (p > 0) {
      cout << "x";
      p--;
    }
    for (long long i = 0; i < a - seg + 2; i++) {
      cout << "o";
    }
    for (long long i = 0; i < q; i++) {
      cout << "x";
    }
    if (p > 0) {
      cout << "x";
      p--;
    }
    for (long long i = 0; i < seg - 2; i++) {
      cout << "o";
      for (long long j = 0; j < q; j++) {
        cout << "x";
      }
      if (p > 0) {
        cout << "x";
        p--;
      }
    }
    cout << endl;
  }
  return 0;
}
