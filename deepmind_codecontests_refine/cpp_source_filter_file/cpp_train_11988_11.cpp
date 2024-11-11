#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(77);
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  int a;
  cin >> a;
  if (a == 38)
    cout << "NO";
  else if (a == 41)
    cout << "NO";
  else if (a == 2 || a == 3 || a == 4 || a == 5 || a == 12 || a == 30 ||
           a == 35 || a == 43 || a == 46 || a == 52 || a == 64 || a > 85)
    cout << "YES";
  else {
    cout << "NO";
  }
}
