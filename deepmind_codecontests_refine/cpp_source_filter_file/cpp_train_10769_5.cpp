#include <bits/stdc++.h>
using namespace std;
long long cnt1[100000];
long long cnt2[100000];
void solve(int pt) {
  if (pt == 100000)
    cout << "=";
  else if (pt == 99999) {
    if (cnt1[pt] > cnt2[pt])
      cout << ">";
    else if (cnt1[pt] < cnt2[pt])
      cout << "<";
    else
      cout << "=";
  } else if (pt <= 99997) {
    if (cnt1[pt] == cnt2[pt]) {
      solve(pt + 1);
    } else if (cnt1[pt] > cnt2[pt]) {
      if (cnt1[pt + 1] >= cnt2[pt + 1]) {
        cout << ">";
      } else if (cnt1[pt + 2] == 1 && cnt2[pt + 2] != 1) {
        cout << "<";
      } else {
        cnt1[pt + 2] = 1 - cnt2[pt + 2];
        cnt2[pt + 2] = 0;
        solve(pt + 2);
      }
    } else {
      if (cnt2[pt + 1] >= cnt1[pt + 1]) {
        cout << "<";
      } else if (cnt2[pt + 2] == 1 && cnt1[pt + 2] != 1) {
        cout << "<";
      } else {
        cnt2[pt + 2] = 1 - cnt1[pt + 2];
        cnt1[pt + 2] = 0;
        solve(pt + 2);
      }
    }
  } else if (pt == 99998) {
    if (cnt1[pt] > cnt2[pt]) {
      cout << ">";
    } else if (cnt1[pt] < cnt2[pt]) {
      cout << "<";
    } else {
      solve(pt + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  while (s.length() != 100000) s += '0';
  reverse(s.begin(), s.end());
  for (int i = 0; i < 100000; i++) {
    cnt1[i] = s[i] - '0';
  }
  cin >> s;
  reverse(s.begin(), s.end());
  while (s.length() != 100000) s += '0';
  reverse(s.begin(), s.end());
  for (int i = 0; i < 100000; i++) {
    cnt2[i] = s[i] - '0';
  }
  solve(0);
}
