#include <bits/stdc++.h>
using namespace std;
string p, q;
int ans = 0;
int pcnt[26] = {0}, pq = 0;
int qcnt[26] = {0};
void check() {
  int dif = 0;
  for (int i = 0; i < 26; ++i) {
    if (pcnt[i] == qcnt[i])
      continue;
    else if (pcnt[i] < qcnt[i])
      dif += qcnt[i] - pcnt[i];
    else
      return;
  }
  if (dif == pq) ++ans;
}
int main() {
  cin >> p >> q;
  if (p.length() < q.length())
    cout << 0 << endl;
  else {
    for (int i = 0; i < q.length(); ++i) {
      if (p[i] == '?')
        ++pq;
      else
        ++pcnt[p[i] - 'a'];
      ++qcnt[q[i] - 'a'];
    }
    check();
    for (int i = q.length(); i < p.length(); ++i) {
      if (p[i - q.length()] == '?')
        --pq;
      else
        --pcnt[p[i - q.length()] - 'a'];
      if (p[i] == '?')
        ++pq;
      else
        ++pcnt[p[i] - 'a'];
      check();
    }
    cout << ans << endl;
  }
  return 0;
}
