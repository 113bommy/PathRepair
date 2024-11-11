#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, m;
  cin >> n >> m;
  if (min(n, m) % 2 == 0)
    cout << "Malvika";
  else
    cout << "Akshat";
  return 0;
}
