#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  int prev = -1;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      if (cnt < b) {
        for (int j = prev + 1; j < i; j++) {
          s[j] = '1';
        }
      }
      cnt = 0;
      prev = i;
    } else {
      cnt++;
    }
  }
  if (cnt < b) {
    for (int i = prev + 1; i < s.size(); i++) {
      s[i] = '1';
    }
  }
  cnt = 0;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      ans = ans + (cnt / b);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  ans = ans + (cnt / b);
  vector<int> v;
  int fans = 0;
  prev = -1;
  int flag = 0;
  cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (flag) {
      break;
    }
    if (s[i] == '1') {
      if (cnt) {
        if (ans - (cnt / b) >= a) {
          ans = ans - (cnt / b);
          fans += (cnt / b);
          int ncnt = 0;
          for (int j = prev + 1; j < i; j++) {
            ncnt++;
            if (ncnt == b) {
              v.push_back(j);
              ncnt = 0;
            }
          }
        } else {
          int ncnt = 0;
          ans = ans - (cnt / b);
          for (int j = prev + 1; j < i; j++) {
            ncnt++;
            if (ncnt == b) {
              v.push_back(j);
              fans++;
              cnt = cnt - b;
              if (ans + (cnt / b) < a) {
                ans = ans + (cnt / b);
                ncnt = 0;
                flag = 1;
                break;
              }
              ncnt = 0;
            }
          }
        }
        cnt = 0;
      }
      prev = i;
    } else {
      cnt++;
    }
  }
  if (cnt) {
    if (ans - (cnt / b) >= a) {
      ans = ans - (cnt / b);
      fans += (cnt / b);
      int ncnt = 0;
      for (int j = prev + 1; j < s.size(); j++) {
        ncnt++;
        if (ncnt == b) {
          v.push_back(j);
          ncnt = 0;
        }
      }
    } else {
      int ncnt = 0;
      ans = ans - (cnt / b);
      for (int j = prev + 1; j < s.size(); j++) {
        ncnt++;
        if (ncnt == b) {
          v.push_back(j);
          fans++;
          cnt = cnt - b;
          if (ans + (cnt / b) < a) {
            ans = ans + (cnt / b);
            ncnt = 0;
            flag = 1;
            break;
          }
          ncnt = 0;
        }
      }
    }
    cnt = 0;
  }
  cout << fans << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] + 1 << " ";
  }
  cout << "\n";
}
