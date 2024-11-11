#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int MAXN = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a, b;
  if (n & 1)
    a = n + 9, b = 9;
  else
    a = n + 4, b = 4;
  cout << a << " " << b << '\n';
  return 0;
}
