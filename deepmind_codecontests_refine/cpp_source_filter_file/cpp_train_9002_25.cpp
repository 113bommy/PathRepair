#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, x2, y1, y2, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
      for (int i = y1; i < y2; i++) res++;
  }
  cout << res;
  return 0;
}
