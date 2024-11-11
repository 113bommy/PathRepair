#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    int m;
    cin >> h >> m;
    cout << (23 - h) * 60 + 60 - m;
  }
  return 0;
}
