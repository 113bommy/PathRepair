#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long b = 1LL << (64 - __builtin_clzll(n));
  cout <<  b - 1 << endl;
}