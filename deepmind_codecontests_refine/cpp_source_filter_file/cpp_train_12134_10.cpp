#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, prevElement, crntElement, mx = 0, cnt = 1;
  cin >> n >> prevElement;
  for (int i = 1; i < n; i++) {
    cin >> crntElement;
    cnt = crntElement > prevElement ? cnt + 1 : 1;
    mx = max(mx, cnt);
    prevElement = crntElement;
  }
  cout << mx;
  return 0;
}
