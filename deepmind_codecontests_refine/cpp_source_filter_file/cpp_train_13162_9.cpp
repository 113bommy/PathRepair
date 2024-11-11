#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, h, max = -1, sum = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> h;
    sum += h;
    if (h > max) max = h;
  }
  sum -= h;
  if (sum <= s)
    cout << "YES";
  else
    cout << "NO";
}
