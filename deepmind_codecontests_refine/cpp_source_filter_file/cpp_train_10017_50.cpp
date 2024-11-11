#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long even = 0;
  long long odd = 0;
  for (long long i = 0; i < n; ++i) {
    long long c;
    cin >> c;
    if (c & 1)
      ++odd;
    else
      ++even;
  }
  if (odd & 1)
    cout << 1 << endl;
  else
    cout << even << endl;
  return 0;
}
