#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p[n];
  for (int i = int(0); i < int(n); i++) cin >> p[i];
  long int c = 0, cur = p[n - 1] + 1;
  for (int i = int(0); i < int(n); i++) {
    if (cur == 0) break;
    if (p[n - 1 - i] < cur) {
      cur = p[n - 1 - i];
    } else {
      cur--;
    }
    c += cur;
  }
  cout << c;
}
