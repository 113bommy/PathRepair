#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = (int)1e9 + 9;
const int mod = (int)1e9 + 7;
int n;
int a[N];
void trans(int ind, string s) {
  int cur = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    cur = cur * 10 + s[i] - '0';
  }
  a[ind] = cur;
}
string s;
string tmp;
void nxt(string prev, string next) {
  tmp = next;
  int n = next.size();
  for (int i = 0; i < n; ++i) {
    if (next[i] == '?') {
      tmp[i] = '9';
    }
  }
  for (int i = 0; i < n; ++i) {
    if (next[i] == '?') {
      if (i > 0) {
        while (tmp[i] > '0') {
          tmp[i]--;
          if (tmp <= prev) {
            tmp[i]++;
            break;
          }
        }
      } else {
        while (tmp[i] > '1') {
          tmp[i]--;
          if (tmp <= prev) {
            tmp[i]++;
            break;
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  string prev;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (i && (prev.size() == s.size())) {
      nxt(prev, s);
      s = tmp;
    } else {
      for (int j = 0; j < (int)s.size(); ++j) {
        if (s[j] == '?') {
          s[j] = j ? '0' : '1';
        }
      }
    }
    trans(i, s);
    prev = s;
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] >= a[i + 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << "\n";
  }
  return 0;
}
