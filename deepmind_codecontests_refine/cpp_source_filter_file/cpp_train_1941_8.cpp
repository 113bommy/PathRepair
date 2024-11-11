#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[2000];
int main() {
  int cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (t[i] > t[j]) cnt++;
    }
  }
  int a, b;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    int x = b - a + 1;
    cnt += x * (x - 1) / 2;
    cnt %= 2;
    if (cnt)
      cout << "ODD" << endl;
    else
      cout << "EVEN" << endl;
  }
  return 0;
}
