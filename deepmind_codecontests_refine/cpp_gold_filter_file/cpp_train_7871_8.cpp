#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int a = 0, b = 1023;
  for (int i = 0; i < n; i++) {
    char op;
    long long int x;
    cin >> op >> x;
    if (op == '|') {
      a |= x;
      b |= x;
    }
    if (op == '&') {
      a &= x;
      b &= x;
    }
    if (op == '^') {
      a ^= x;
      b ^= x;
    }
  }
  long long int orr = 0, andd = 1023, xorr = 0;
  for (long long int i = 0; i < 10; i++) {
    if (((1LL << i) & a) && ((1LL << i) & b)) {
      orr ^= (1LL << i);
    }
    if (((1LL << i) & a) && (!((1LL << i) & b))) {
      xorr ^= (1LL << i);
    }
    if (!(((1LL << i) & a)) && !((1LL << i) & b)) {
      andd ^= (1LL << i);
    }
  }
  cout << "3\n";
  cout << "& " << andd << "\n";
  cout << "| " << orr << "\n";
  cout << "^ " << xorr << "\n";
  return 0;
}
