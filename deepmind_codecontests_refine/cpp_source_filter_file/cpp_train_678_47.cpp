#include <bits/stdc++.h>
using namespace std;
int main(int, char**) {
  std::ios::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  cout << (n % 2) ? n / 2 : n / 2 + 1;
  return 0;
};
