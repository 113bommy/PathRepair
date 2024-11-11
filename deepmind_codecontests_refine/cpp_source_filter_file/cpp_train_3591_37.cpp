#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  if (m >= n - m)
    cout << max(1, m - 1);
  else
    cout << m + 1;
  return 0;
}
