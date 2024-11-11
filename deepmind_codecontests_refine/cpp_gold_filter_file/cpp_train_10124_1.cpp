#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int MAX = n + 2;
  vector<int> L1(MAX), L2(MAX), L3(MAX), R1(MAX), R2(MAX), R3(MAX);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      L1[i + 1] = i + 1;
      L2[i + 1] = L2[i];
      L3[i + 1] = L3[i];
    } else if (s[i] == '2') {
      L2[i + 1] = i + 1;
      L1[i + 1] = L1[i];
      L3[i + 1] = L3[i];
    } else {
      L3[i + 1] = i + 1;
      L1[i + 1] = L1[i];
      L2[i + 1] = L2[i];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      R1[i + 1] = i + 1;
      R2[i + 1] = R2[i + 2];
      R3[i + 1] = R3[i + 2];
    } else if (s[i] == '2') {
      R2[i + 1] = i + 1;
      R1[i + 1] = R1[i + 2];
      R3[i + 1] = R3[i + 2];
    } else {
      R3[i + 1] = i + 1;
      R1[i + 1] = R1[i + 2];
      R2[i + 1] = R2[i + 2];
    }
  }
  int cur = 1e8;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && R2[i + 2] != 0 && R3[i + 2] != 0) {
      cur = min(cur, max(R2[i + 2], R3[i + 2]) - L1[i + 1] + 1);
    }
    if (s[i] == '2' && R1[i + 2] != 0 && R3[i + 2] != 0) {
      cur = min(cur, max(R3[i + 2], R1[i + 2]) - L2[i + 1] + 1);
    }
    if (s[i] == '3' && R2[i + 2] != 0 && R1[i + 2] != 0) {
      cur = min(cur, max(R1[i + 2], R2[i + 2]) - L3[i + 1] + 1);
    }
  }
  if (cur == (int)1e8) {
    cout << 0 << endl;
    return;
  }
  cout << cur << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
