#include <bits/stdc++.h>
using namespace std;
const int MAXC = 26;
const int MAXN = 200020;
int last[MAXC], fwd[MAXN], bwd[MAXN];
string s, t;
int main() {
  cin >> s >> t;
  int ssz = s.size();
  int tsz = t.size();
  memset(last, -1, sizeof last);
  int sidx = 0;
  for (int i = 0; i < tsz; i++) {
    while (sidx < ssz && s[sidx] != t[i]) {
      fwd[sidx] = last[s[sidx] - 'a'];
      if (fwd[sidx] == -1) {
        cout << "No" << endl;
        return 0;
      }
      sidx++;
    }
    if (sidx == ssz) {
      cout << "No" << endl;
      return 0;
    }
    fwd[sidx] = last[s[sidx] - 'a'] = i;
    sidx++;
  }
  while (sidx < ssz) {
    fwd[sidx] = last[s[sidx] - 'a'];
    if (fwd[sidx] == -1) {
      cout << "No" << endl;
      return 0;
    }
    sidx++;
  }
  memset(last, -1, sizeof last);
  sidx = ssz - 1;
  for (int i = tsz - 1; i >= 0; i--) {
    while (sidx >= 0 && s[sidx] != t[i]) {
      bwd[sidx] = last[s[sidx] - 'a'];
      if (bwd[sidx] == -1) {
        cout << "No" << endl;
        return 0;
      }
      sidx--;
    }
    if (sidx == 0) {
      cout << "No" << endl;
      return 0;
    }
    bwd[sidx] = last[s[sidx] - 'a'] = i;
    sidx--;
  }
  while (sidx >= 0) {
    bwd[sidx] = last[s[sidx] - 'a'];
    if (bwd[sidx] == -1) {
      cout << "No" << endl;
      return 0;
    }
    sidx--;
  }
  for (int i = 0; i < ssz; i++) {
    if (fwd[i] < bwd[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
