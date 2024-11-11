#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6 + 1;
const int INF = 2e9;
long long k;
string second;
int main() {
  cin >> k;
  for (int i = 1; i <= k / 2; ++i) {
    second += "8";
  }
  if (k % 2 != 0) second += "6";
  if (second.size() > 18) {
    cout << -1 << endl;
    exit(0);
    ;
  }
  cout << second << endl;
  exit(0);
  ;
}
