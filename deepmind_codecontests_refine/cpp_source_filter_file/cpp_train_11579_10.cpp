#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> v;
int main() {
  int tota, totb, n;
  cout << string(300, 'a') << endl;
  fflush(stdout);
  cin >> tota;
  if (!tota) {
    return 0;
  }
  tota = n - tota;
  cout << string(300, 'b') << endl;
  fflush(stdout);
  cin >> totb;
  if (!totb) {
    return 0;
  }
  totb = n - totb;
  n = tota + totb;
  string res = "";
  int ok = 0, len = 0;
  for (int i = 0; i <= totb - 1; ++i) {
    if (ok == tota) {
      res += 'b';
      continue;
    }
    string ancient = res;
    res += 'a';
    ok++;
    len++;
    cout << res;
    for (int j = i + 1; j <= totb; ++j) {
      cout << 'b';
    }
    puts("");
    fflush(stdout);
    int tmp;
    cin >> tmp;
    if (tmp == 0) {
      return 0;
    }
    if (tmp == n - totb - ok) {
      i--;
    } else {
      res = ancient;
      res += 'b';
      ok--;
      continue;
    }
  }
  for (int i = ok + 1; i <= tota; ++i) {
    res += 'a';
  }
  cout << res << endl;
  fflush(stdout);
  int LALALL;
  cin >> LALALL;
  return 0;
}
