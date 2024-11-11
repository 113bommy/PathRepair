#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, a, b;
  cin >> w >> a >> b;
  cout << max(0, min(b - a - w, a - b - w)) << endl;
}
