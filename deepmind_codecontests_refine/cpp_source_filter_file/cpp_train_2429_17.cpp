#include <bits/stdc++.h>
using namespace std;
vector<int> tick1;
vector<int> tick2;
int tak[202];
int re(int t) {
  if (t == '0') return 0;
  if (t == '1') return 1;
  if (t == '2') return 2;
  if (t == '3') return 3;
  if (t == '4') return 4;
  if (t == '5') return 5;
  if (t == '6') return 6;
  if (t == '7') return 7;
  if (t == '8') return 8;
  if (t == '9') return 9;
}
int main() {
  int n, s1 = 0, s2 = 0, a;
  char t;
  bool flag = true;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> t;
    a = re(t);
    if (i <= n - 1) {
      tick1.push_back(a);
      s1 += a;
    } else {
      tick2.push_back(a);
      s2 += a;
    }
  }
  a = 0;
  if (s2 == s1) {
    cout << "YES" << endl;
  } else {
    sort(tick1.begin(), tick1.end());
    sort(tick2.begin(), tick2.end());
    if (tick1[0] < tick2[0]) {
      a = 0;
    } else
      a = 1;
    for (int i = 0; i < n; i++) {
      if (a == 0 && tick1[i] >= tick2[i]) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
      if (a == 1 && tick1[i] <= tick2[i]) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
