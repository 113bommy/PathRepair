#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int h;
  int m;
  for (int i = 0; i < t; i++) {
    cin >> h;
    cin >> m;
    h = abs(((23 - h) * 60));
    m = abs((60 - m));
    m = m + h;
    cout << m << endl;
  }
}
