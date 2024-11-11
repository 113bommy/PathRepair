#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
  int i, j, k, n, m, l;
  cin >> n;
  queue<int> sh;
  int d[n + 1], s[n + 1], sum = 0;
  for (i = 0; i < n; i++) {
    cin >> d[i] >> s[i];
    sum += d[i];
    if (d[i] == 1) sh.push(i);
  }
  cout << sum / 2 << endl;
  while (!sh.empty()) {
    int pk = sh.front();
    sh.pop();
    if (d[pk] == 0) continue;
    cout << pk << " " << s[pk] << " " << endl;
    s[s[pk]] ^= pk;
    d[pk]--;
    if (--d[s[pk]] == 1) {
      sh.push(s[pk]);
    }
  }
  return 0;
}
