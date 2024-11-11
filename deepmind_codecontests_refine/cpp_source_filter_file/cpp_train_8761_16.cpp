#include <bits/stdc++.h>
using namespace std;
const int size1 = 4e5 + 50;
using pt = pair<long long, long long>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  string s;
  string s1 = "tokitsukaze";
  string s2 = "quality";
  string s3 = "once again";
  cin >> n >> k >> s;
  static int pr0[size1], pr1[size1], nxt0[size1], nxt1[size1];
  int prev0 = -1, prev1 = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      prev0 = i;
    } else {
      prev1 = i;
    }
    pr0[i] = prev0;
    pr1[i] = prev1;
  }
  int suf0 = -1, suf1 = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      suf0 = i;
    } else {
      suf1 = i;
    }
    nxt0[i] = suf0;
    nxt1[i] = suf1;
  }
  bool res = false;
  for (int i = 0; i < n - k + 1; i++) {
    if ((i == 0 || pr0[i - 1] == -1) && (i + k == n || nxt0[i + k] == -1)) {
      res = true;
    }
    if ((i == 0 || pr1[i - 1] == -1) && (i + k == n || nxt1[i + k] == -1)) {
      res = true;
    }
  }
  if (res) {
    cout << s1;
    return 0;
  }
  bool res1 = false;
  for (int i = 0; i < n - k + 1; i++) {
    {
      bool canl = false;
      bool canr = false;
      if (i != 0 && pr0[i - 1] != -1) {
        canl = true;
      }
      if (i + k != n && nxt0[i + k] != -1) {
        canr = true;
      }
      if (canl && canr) {
        res1 = true;
      }
      if (canl) {
        if (pr0[i - 1] - nxt0[0] >= k) {
          res1 = true;
        }
      }
      if (canr) {
        if (pr0[n - 1] - nxt0[i + k] >= k) {
          res1 = true;
        }
      }
    }
    {
      bool canl = false;
      bool canr = false;
      if (i != 0 && pr1[i - 1] != -1) {
        canl = true;
      }
      if (i + k != n && nxt1[i + k] != -1) {
        canr = true;
      }
      if (canl && canr) {
        res1 = true;
      }
      if (canl) {
        if (pr1[i - 1] - nxt1[0] >= k) {
          res1 = true;
        }
      }
      if (canr) {
        if (pr1[n - 1] - nxt1[i + k] >= k) {
          res1 = true;
        }
      }
    }
  }
  if (!res1) {
    cout << s2;
    return 0;
  }
  cout << s3;
  return 0;
}
