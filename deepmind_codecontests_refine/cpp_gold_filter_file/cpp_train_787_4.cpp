#include <bits/stdc++.h>
using namespace std;
int main() {
  string ansl, ansr;
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  int n = s.length();
  deque<char> a, b;
  for (int i = 0; i < (n + 1) / 2; i++) {
    a.push_back(s[i]);
  }
  for (int i = 0; i < n / 2; i++) {
    b.push_back(t[i]);
  }
  int mood = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if (!a.empty() && a[0] >= b[0]) {
        mood = 1;
      }
      if (mood) {
        ansr += b.back();
        b.pop_back();
      } else {
        ansl += b[0];
        b.pop_front();
      }
    } else {
      if (!b.empty() && a[0] >= b[0]) {
        mood = 1;
      }
      if (mood) {
        ansr += a.back();
        a.pop_back();
      } else {
        ansl += a[0];
        a.pop_front();
      }
    }
  }
  reverse(ansr.begin(), ansr.end());
  ansl += ansr;
  cout << ansl;
}
