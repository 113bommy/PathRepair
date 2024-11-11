#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  int t;
  cin >> t;
  while (t--) {
    int i;
    cin >> i;
    if (i % 2 == 0)
      cout << i / 2 << '\n';
    else
      cout << (i - 3) / 2 + 1 << '\n';
  }
  return 0;
}
