#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 1, ans = 1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    ans = ans + cnt;
    cout << ((ans) % n) << " ";
    cnt++;
  }
  return 0;
}
