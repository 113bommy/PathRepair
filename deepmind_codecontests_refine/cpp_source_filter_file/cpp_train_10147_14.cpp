#include <bits/stdc++.h>
const int OO = (long long)2e9;
const double eps = 1e-9;
const long long MAX = 400010;
const long long MOD = 256;
using namespace std;
long long n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  if (n & 1)
    cout << "black";
  else
    cout << "White\n"
         << "1 2";
  return 0;
}
