#include <bits/stdc++.h>
using namespace std;
int check[55];
int n;
int main() {
  cin >> n;
  int i;
  int m = 50;
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x < m) m = x;
    check[x]++;
  }
  for (i = m + 1; i <= 50; i++) {
    cnt += check[i];
  }
  if (cnt >= n / 2) {
    cout << "Alice";
  } else {
    cout << "Bob";
  }
  return 0;
}
