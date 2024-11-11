#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, b, a1[100001], p[100001];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    a1[a] = i;
  }
  for (i = 0; i < n; i++) {
    cin >> b;
    p[i] = a1[b];
  }
  for (i = 0; i < n; i++) {
    cout << (p[i] + 1) << ' ';
  }
  return 0;
}
