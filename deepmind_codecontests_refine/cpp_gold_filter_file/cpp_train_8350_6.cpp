#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int h, m;
    cin >> h >> m;
    int k = 23 - h;
    int l = 60 - m;
    cout << k * 60 + l << endl;
  }
  return 0;
}
