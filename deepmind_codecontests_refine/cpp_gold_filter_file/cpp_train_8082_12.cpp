#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int a, o = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    o += (a % 2 == 0);
  }
  cout << min(o, n - o) + (n - o - min(o, n - o)) / 3;
  return 0;
}
