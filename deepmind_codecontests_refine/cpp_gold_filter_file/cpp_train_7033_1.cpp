#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int pass[N];
int rasp[N];
int need[N];
int k;
bool check(int m) {
  map<int, int> last;
  for (int i = 1; i <= m; i++) {
    pass[i] = 0;
    if (rasp[i]) {
      pass[last[rasp[i]]] = 0;
      pass[i] = rasp[i];
      last[rasp[i]] = i;
    }
  }
  int ans = 0;
  int kk = 0;
  for (int i = 1; i <= m; i++) {
    if (pass[i] == 0) {
      ans++;
    } else {
      kk++;
      ans -= need[pass[i]];
      if (ans < 0) {
        return 0;
      }
    }
  }
  return k == kk;
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> rasp[i];
  }
  for (int i = 1; i <= k; i++) {
    cin >> need[i];
  }
  int l = 0;
  int r = n + 1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << (l == n ? -1 : l + 1) << endl;
}
