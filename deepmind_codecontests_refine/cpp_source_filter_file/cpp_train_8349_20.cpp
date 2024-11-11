#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  while (a--) {
    int h, m;
    cin >> h >> m;
    cout << (24 - h) * 60 + (60 - m) << endl;
  }
  return 0;
}
