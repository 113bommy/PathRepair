#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  bool a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  bool ans = (((a1 | a2) & (a3 ^ a4)) ^ ((a2 & a3) ^ (a1 | a4)));
  cout << ans;
  return 0;
}
