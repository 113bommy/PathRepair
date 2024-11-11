#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    cout << 1440 - (h * 60) - m;
  }
}
