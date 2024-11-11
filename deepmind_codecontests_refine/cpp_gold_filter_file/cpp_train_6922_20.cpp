#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int c[100000], d[100000];
  int k, m, i, j;
  cin >> a >> b;
  cin >> k >> m;
  for (i = 0; i < a; i++) cin >> c[i];
  for (j = 0; j < b; j++) cin >> d[j];
  if (c[k - 1] >= d[b - m])
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
