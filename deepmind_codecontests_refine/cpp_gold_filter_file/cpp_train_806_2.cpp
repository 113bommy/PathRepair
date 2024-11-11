#include <bits/stdc++.h>
using namespace std;
int main()
  {long long N, m{}, s{}, A; cin >> N;
  while (cin >> A) s += max(0LL, m - A), m = max(m, A);
  cout << s;}