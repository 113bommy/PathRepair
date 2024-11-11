#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  long long int second;
  long long int length;
};
int main() {
  long long int i, w, m, j, k;
  cin >> w >> m;
  long long int a[101];
  memset(a, 0, sizeof(a));
  long long int s = m;
  j = 0;
  while (m) {
    a[j++] = m % w;
    m = m / w;
  }
  for (i = 0; i <= 100; i++) {
    if (a[i] == 0 || a[i] == 1)
      continue;
    else if (a[i] == w - 1 || a[i - 1] == w)
      a[i + 1]++;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
