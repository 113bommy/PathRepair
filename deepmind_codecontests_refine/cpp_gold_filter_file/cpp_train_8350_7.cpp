#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int h, m;
  while (t--) {
    cin >> h >> m;
    cout << (24 - h - 1) * 60 + (60 - m) << "\n";
  }
}
