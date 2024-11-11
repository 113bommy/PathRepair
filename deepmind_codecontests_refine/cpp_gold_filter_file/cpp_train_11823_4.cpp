#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  int Max = max(max(a1, a2), a3);
  int Min = min(min(a1, a2), a3);
  cout << Max - Min << endl;
  return 0;
}
