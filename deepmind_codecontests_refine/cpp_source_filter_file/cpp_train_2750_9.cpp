#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000] = {0}, n, s, max = 0, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (a[s] == 0) cnt++;
    a[s]++;
    max = a[s] > max ? a[s] : max;
  }
  cout << max << " " << cnt;
}
