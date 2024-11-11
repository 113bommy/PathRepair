#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i;
  cin >> n;
  int d[n - 1];
  for (i = 0; i < n - 1; i++) cin >> d[i];
  cin >> a >> b;
  int s = 0;
  for (i = a - 1; i < b; i++) s += d[i];
  cout << s;
  return 0;
}
