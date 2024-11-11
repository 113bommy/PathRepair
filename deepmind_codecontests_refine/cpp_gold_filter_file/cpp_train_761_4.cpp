#include <bits/stdc++.h>
using namespace std;
bool x[3001][3001] = {
    0,
};
int n, s;
int a[3001], b[3001];
int main() {
  cin >> n;
  s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    x[a[i] + 1000][b[i] + 1000] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (((a[i] + a[j]) % 2 == 0) && ((b[i] + b[j]) % 2 == 0)) {
        if (x[1000 + (a[i] + a[j]) / 2][1000 + (b[i] + b[j]) / 2] == 1) {
          s++;
        }
      }
    }
  }
  cout << s;
  return 0;
}
