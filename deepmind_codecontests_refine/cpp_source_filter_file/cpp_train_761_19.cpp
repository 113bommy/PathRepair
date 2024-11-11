#include <bits/stdc++.h>
using namespace std;
int freq[2001][2001];
int x[3001], y[3001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    freq[x[i] + 1000][y[i] + 1000]++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((x[i] + x[j]) % 2 == 1 || (y[i] + y[j]) % 2 == 1) continue;
      int mdx = (x[i] + x[j]) / 2;
      int mdy = (y[i] + y[j]) / 2;
      if (freq[mdx + 1000][mdy + 1000]) cnt++;
    }
  }
  cout << cnt;
  return 0;
}
