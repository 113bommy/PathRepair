#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *p, *q;
  p = new int[n + 1];
  q = new int[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    q[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << q[i] << " ";
  }
}
