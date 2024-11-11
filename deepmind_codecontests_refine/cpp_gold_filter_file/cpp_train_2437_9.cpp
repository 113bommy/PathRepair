#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int go[1111];
  int n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> go[i];
  sort(go, go + n);
  swap(go[n - 1], go[0]);
  for (i = 0; i < n; i++) cout << go[i] << ' ';
  return 0;
}
