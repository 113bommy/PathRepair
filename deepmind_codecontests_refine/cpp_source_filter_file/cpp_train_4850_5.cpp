#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000, INDEX = 1;
int n, k, lastFree[MAX_N + INDEX];
bool isBusy[MAX_N + INDEX];
bool isGood(int x) {
  int c = 1, lastBars = 1;
  while (lastBars < n) {
    lastBars = lastFree[min(n, lastBars + x + 1)];
    c++;
    if (c > n) {
      return false;
    }
  }
  return c <= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      isBusy[i + 1] = true;
    }
    if (s[i] == '0') {
      isBusy[i + 1] = false;
    }
  }
  lastFree[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (!isBusy[i]) {
      lastFree[i] = i;
    } else {
      lastFree[i] = lastFree[i - 1];
    }
  }
  int l = 1, r = n;
  while (r > l) {
    int m = (l + r) / 2;
    if (isGood(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << (l + r) / 2 << endl;
  return 0;
}
