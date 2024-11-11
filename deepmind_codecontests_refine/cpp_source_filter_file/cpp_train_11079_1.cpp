#include <bits/stdc++.h>
using namespace std;
int piles = 1, heavy = 0, num;
int a[110], n;
void solve(int x) {
  if (num == 0) {
    return;
  }
  if (heavy <= a[x]) {
    a[x] = -1;
    heavy++;
    num--;
    solve(x + 1);
  } else if (x < n) {
    solve(x + 1);
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i] != -1) {
        a[i] = -1;
        num--;
        heavy = 1;
        piles++;
        break;
      }
    }
    solve(1);
  }
}
int main() {
  cin >> n;
  num = n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
  solve(1);
  cout << piles;
  return 0;
}
