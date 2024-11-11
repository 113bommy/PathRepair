#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    int h, m;
    cin >> h >> m;
    cout << (60 - m) + 60 * (23 - h) << endl;
  }
  return 0;
}
