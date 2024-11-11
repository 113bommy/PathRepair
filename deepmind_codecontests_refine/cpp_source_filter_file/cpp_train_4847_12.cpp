#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = 1000006;
  int res = 1;
  for (int i = 1; i < n; i++) res = (res * 3) % m;
  cout << res << endl;
  return 0;
}
