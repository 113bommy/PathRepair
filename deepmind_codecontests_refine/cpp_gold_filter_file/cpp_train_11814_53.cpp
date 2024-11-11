#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int m, n;
  cin >> m >> n;
  int c = m * n;
  if (m && n <= 16) {
    cout << floor(c / 2);
  }
  return 0;
}
