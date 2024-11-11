#include <bits/stdc++.h>
using namespace std;
int N, M;
string m[105];
queue<int> q;
int cf = 0;
bool goal() { return (cf + 1 == N); }
int main(void) {
  int i, j, k;
  long long ans = 0;
  cin >> N >> M;
  for (i = 0; i < N; i++) {
    cin >> m[i];
    m[i] = "#" + m[i] + "#";
  }
  int rmp, lmp, cp, sp, np;
  rmp = lmp = cp = sp = 1;
  bool r = true;
  while (!goal()) {
    if (m[cf + 1][cp] == '.') {
      ++cf;
      lmp = rmp = cp;
      ++ans;
      continue;
    }
    if (m[cf][rmp + 1] == '#' && m[cf][lmp - 1] == '#') {
      break;
    }
    np = (r) ? rmp + 1 : lmp - 1;
    if (m[cf][np] == '.') {
      cp = (r) ? ++rmp : --lmp;
      ++ans;
    } else if (m[cf][np] == '+') {
      m[cf][np] = '.';
      r = !r;
      cp = (r) ? rmp : lmp;
      ans += (rmp - lmp) + 1;
    } else {
      r = !r;
      cp = (r) ? rmp : lmp;
      ans += (rmp - lmp) + 1;
    }
  }
  if (goal()) {
    cout << ans << endl;
  } else {
    cout << "Never" << endl;
  }
  return 0;
}
