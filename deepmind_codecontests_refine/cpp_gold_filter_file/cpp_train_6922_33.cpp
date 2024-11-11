#include <bits/stdc++.h>
using namespace std;
int a[100002], b[100002];
int aa, bb;
int main() {
  int al, bl;
  cin >> al >> bl;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= al; i++) {
    cin >> a[i];
    if (i == n) aa = a[i];
  }
  for (int i = 1; i <= bl; i++) {
    cin >> b[i];
    if (i == bl - m + 1) bb = b[i];
  }
  if (aa >= bb)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
