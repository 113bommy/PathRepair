#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mx = 0, cnt = 0;
  cin >> n;
  int man = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 1)
      man += x;
    else {
      if (man == 0)
        cnt++;
      else
        man--;
    }
  }
  cout << cnt << endl;
}
