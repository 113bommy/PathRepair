#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, d[N], c, res, f[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> c >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    d[a]++;
  }
  f[0] = N + 1;
  for (int i = 1; i <= c; i++)
    if (d[i])
      f[i] = i;
    else
      f[i] = f[i - 1];
  for (int i = 1; i <= c; i++) {
    d[i]++;
    int cur = c;
    int nextNumber = c;
    bool done = false;
    while (cur != 0) {
      nextNumber = f[nextNumber];
      if (i <= cur && !done && i > nextNumber) {
        nextNumber = max(nextNumber, i);
        done = true;
      }
      if (nextNumber > cur) break;
      int t = min(d[nextNumber], cur / nextNumber);
      cur -= t * nextNumber;
      nextNumber = min(nextNumber - 1, cur);
    }
    if (cur != 0) {
      cout << i << endl;
      return 0;
    }
    d[i]--;
  }
  cout << "Greed is good" << endl;
  return 0;
}
