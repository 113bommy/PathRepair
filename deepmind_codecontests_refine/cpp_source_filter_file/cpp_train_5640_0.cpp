#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> u;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    u[x]++;
    u[y]++;
  }
  for (auto ele : u) {
    if (ele.second == 2) return !printf("NO");
  }
  cout << "YES";
  return 0;
}
