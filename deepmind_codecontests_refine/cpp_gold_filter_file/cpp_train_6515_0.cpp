#include <bits/stdc++.h>
using namespace std;
int main() {
  int maxx = 0;
  int n;
  cin >> n;
  int last;
  for (int(i) = (0); (i) < (n); i++) {
    cin >> last;
    maxx = max(maxx, last);
  }
  cout << (maxx ^ last);
  return 0;
}
