#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, A, D;
  string a;
  cin >> n;
  cin >> a;
  A = D = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'A')
      A++;
    else if (a[i] == 'D')
      D++;
  }
  if (A > D)
    cout << "Anton" << endl;
  else if (A < D)
    cout << "Danik" << endl;
  else
    cout << "Freindship" << endl;
  return 0;
}
