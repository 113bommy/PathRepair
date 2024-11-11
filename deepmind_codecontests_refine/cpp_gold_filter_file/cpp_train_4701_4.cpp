#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
stack<pair<char, int> > sta, sta2;
string ans;
int main() {
  int n;
  string a;
  cin >> n >> a;
  ans = a;
  if (n % 2 == 1 || a[0] == ')' || a[n - 1] == '(') {
    cout << ":(" << endl;
    return 0;
  }
  ans[0] = '(';
  ans[n - 1] = ')';
  for (int i = 1; i < n / 2; i++) {
    if (a[i] == '(') {
      sta.push(make_pair('(', i));
      ans[i] = '(';
    } else if (a[i] == ')') {
      if (sta.empty()) {
        cout << ":(" << endl;
        return 0;
      } else {
        if (sta.top().first == '?') {
          ans[sta.top().second] = '(';
        }
        sta.pop();
        ans[i] = ')';
      }
    } else if (a[i] == '?') {
      if (sta.empty()) {
        sta.push(make_pair('(', i));
        ans[i] = '(';
      } else {
        sta.push(make_pair('?', i));
        ans[i] = '?';
      }
    }
  }
  for (int i = n - 2; i >= n / 2; i--) {
    if (a[i] == ')') {
      sta2.push(make_pair(')', i));
      ans[i] = ')';
    } else if (a[i] == '(') {
      if (sta2.empty()) {
        cout << ":(" << endl;
        return 0;
      } else {
        if (sta2.top().first == '?') {
          ans[sta2.top().second] = ')';
        }
        sta2.pop();
        ans[i] = '(';
      }
    } else if (a[i] == '?') {
      if (sta2.empty()) {
        sta2.push(make_pair(')', i));
        ans[i] = ')';
      } else {
        sta2.push(make_pair('?', i));
        ans[i] = '?';
      }
    }
  }
  if (sta.size() > sta2.size()) {
    int m = (sta.size() - sta2.size()) / 2;
    int p = 0, q = 0;
    while (p < m) {
      if (sta.top().first == '(') {
        sta.pop();
        q++;
        if (q > p + sta2.size()) {
          cout << ":(" << endl;
          return 0;
        }
        continue;
      }
      ans[sta.top().second] = ')';
      sta.pop();
      p++;
    }
  } else if (sta.size() < sta2.size()) {
    int m = (sta2.size() - sta.size()) / 2;
    int p = 0, q = 0;
    while (p < m) {
      if (sta2.top().first == ')') {
        sta2.pop();
        q++;
        if (q > p + sta.size()) {
          cout << ":(" << endl;
          return 0;
        }
        continue;
      }
      ans[sta2.top().second] = '(';
      sta2.pop();
      p++;
    }
  }
  while (sta.size()) {
    ans[sta.top().second] = '(';
    sta.pop();
  }
  while (sta2.size()) {
    ans[sta2.top().second] = ')';
    sta2.pop();
  }
  cout << ans;
  return 0;
}
