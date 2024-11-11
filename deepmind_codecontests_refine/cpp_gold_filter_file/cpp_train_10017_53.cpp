#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, o, n;
  o = 0;
  cin >> q;
  int qc = q;
  while (q--) {
    cin >> n;
    if (n % 2) o++;
  }
  if (o % 2)
    cout << o;
  else
    cout << qc - o;
  return 0;
}
