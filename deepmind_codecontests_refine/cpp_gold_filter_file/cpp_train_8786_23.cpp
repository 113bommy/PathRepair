#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, a[1000];
  int i;
  cin >> m;
  a[0] = 0;
  for ((i) = (1); (i) <= (m); ++(i)) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }
  int first, second;
  cin >> first >> second;
  for ((i) = (1); (i) <= (m); ++(i))
    if (a[i] <= second && a[i] >= first && a[m] - a[i] <= second &&
        a[m] - a[i] >= first) {
      cout << i + 1 << endl;
      return 0;
    }
  cout << 0 << endl;
  return 0;
}
