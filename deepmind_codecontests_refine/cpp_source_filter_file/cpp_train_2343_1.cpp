#include <bits/stdc++.h>
using namespace std;
int w[1000005 + 35];
int main() {
  ios_base::sync_with_stdio(false);
  int n, i, j, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    w[x]++;
  }
  for (i = 0; i < 1000005; i++) {
    w[i + 1] += w[i] / 2;
    w[i] %= 2;
  }
  int s = 0;
  for (i = 0; i < 1000005 + 33; i++) {
    s += w[i];
  }
  cout << s << endl;
}
