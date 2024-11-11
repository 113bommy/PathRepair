#include <bits/stdc++.h>
using namespace std;
int d[100005];
int main() {
  int n, m, z;
  cin >> n >> m;
  z = min(n, m);
  if (z % 2 == 0) cout << "Malvika";
  if (z % 2 == 1) cout << "Akshat";
  return 0;
}
