#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  int nQ;
  vector<long long> qs;
  cin >> n >> k >> nQ;
  if (n == k) {
    for (int i = 0; i < nQ; ++i) {
      cout << "X";
    }
    cout << endl;
    return 0;
  }
  if (k == 0) {
    for (int i = 0; i < nQ; ++i) {
      cout << ".";
    }
    cout << endl;
    return 0;
  }
  long long X = k, D = n - X;
  long long b = min(X, D);
  if (b % 2 != D % 2) --b;
  long long c = D - b;
  if (c == 0) {
    c = 1;
    --b;
  } else {
    if (b == 1) {
      --b;
      c += 1;
    }
  }
  for (int i = 0; i < nQ; ++i) {
    long long x;
    cin >> x;
    if (x <= c) {
      cout << ".";
    } else {
      x -= c;
      if (x <= 2 * b + 1) {
        if (x % 2 == 1)
          cout << "X";
        else
          cout << ".";
      } else {
        cout << "X";
      }
    }
  }
  cout << endl;
}
