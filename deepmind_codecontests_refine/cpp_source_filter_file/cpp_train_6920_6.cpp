#include <bits/stdc++.h>
using namespace std;
int main() {
  int e, n;
  cin >> e >> n;
  int t = 0;
  int n1 = max(e, n), e1 = min(e, n);
  int k = n1 - e1;
  if (e1 < k)
    t = e;
  else
    t = k + 2 * (e1 - k) / 3 + ((e1 - k) % 3 == 2);
  cout << t << endl;
}
