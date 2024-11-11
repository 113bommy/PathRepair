#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int s, a, b, c;
    cin >> s >> a >> b >> c;
    long long int totalChoc, boughtChoc, freeChoc;
    boughtChoc = s / c;
    freeChoc = (boughtChoc / a) * b;
    totalChoc = freeChoc + boughtChoc;
    cout << totalChoc << endl;
  }
  return 0;
}
