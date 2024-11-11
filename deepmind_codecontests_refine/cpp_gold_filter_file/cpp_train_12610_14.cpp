#include <bits/stdc++.h>
long long mod = 1e9 + 7;
const int MAX = 1e5 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt[3] = {};
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']++;
  }
  int tot = n / 3;
  if (cnt[0] == tot && cnt[1] == tot && cnt[2] == tot) {
    cout << s;
    return 0;
  }
  if (cnt[0] < tot) {
    for (int i = 0; i < n; i++) {
      if (cnt[0] == tot) break;
      if (s[i] == '1') {
        if (cnt[1] > tot) {
          s[i] = '0';
          cnt[0]++;
          cnt[1]--;
        }
      }
      if (s[i] == '2') {
        if (cnt[2] > tot) {
          s[i] = '0';
          cnt[0]++;
          cnt[2]--;
        }
      }
    }
  }
  if (cnt[1] < tot) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        if (cnt[1] == tot) break;
        if (cnt[2] > tot) {
          s[i] = '1';
          cnt[1]++;
          cnt[2]--;
        }
      }
    }
    if (cnt[2] < tot) {
      for (int i = n - 1; i >= 0; i--) {
        if (cnt[2] == tot) break;
        if (s[i] == '0') {
          if (cnt[0] > tot) {
            s[i] = '2';
            cnt[2]++;
            cnt[0]--;
          }
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (cnt[1] == tot) break;
      if (s[i] == '0') {
        if (cnt[0] > tot) {
          s[i] = '1';
          cnt[1]++;
          cnt[0]--;
        }
      }
    }
  }
  if (cnt[2] < tot) {
    for (int i = n - 1; i >= 0; i--) {
      if (cnt[2] == tot) break;
      if (s[i] == '0') {
        if (cnt[0] > tot) {
          s[i] = '2';
          cnt[2]++;
          cnt[0]--;
        }
      }
      if (s[i] == '1') {
        if (cnt[1] > tot) {
          s[i] = '2';
          cnt[2]++;
          cnt[1]--;
        }
      }
    }
  }
  cout << s;
  return 0;
}
