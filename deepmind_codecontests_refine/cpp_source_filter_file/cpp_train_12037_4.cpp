#include <bits/stdc++.h>
using namespace std;
int ara[110];
int main() {
  int n, x, i, p;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> p;
    ara[p]++;
  }
  int cnt = 0;
  if (ara[p] == 1) cnt = 1;
  for (i = 0; i < x; i++) {
    if (ara[i] == 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
