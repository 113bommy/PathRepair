#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int SIZE = 100000005;
const int Size = 100005;
const int MOD = 1000000007;
const double PI = 2 * acos(0.0);
const long long INF = 214738360000;
int main() {
  int n, i;
  string str;
  cin >> n >> str;
  if (str.size() == 1) {
    cout << str;
    return 0;
  }
  for (i = n - 2; i >= 0; i -= 2) {
    cout << str[i];
  }
  for (i = 1 - n % 2; i < n; i += 2) {
    cout << str[i];
  }
  return 0;
}
