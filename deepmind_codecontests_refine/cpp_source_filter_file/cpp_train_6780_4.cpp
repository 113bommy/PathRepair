#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long int k;
  cin >> k;
  long long int cnt1 = 0, cnt2 = 0;
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == '?') {
      cnt1++;
    } else if (s[i] == '*') {
      cnt2++;
    }
  }
  bool yup = true;
  long long int lm = s.length() - 2 * (cnt1 + cnt2);
  if (k < lm) {
    yup = false;
  }
  long long int lmx = lm + cnt1 + cnt2;
  if (cnt2 == 0 && k > lmx) {
    yup = false;
  }
  if (!yup) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (k <= lmx) {
    long long int xd = lmx - k;
    for (long long int i = 0; i < s.length() - 1; i++) {
      if (xd > 0) {
        if (s[i + 1] == '?' || s[i + 1] == '*') {
          xd--;
        } else if (s[i] != '?' && s[i] != '*') {
          cout << s[i];
        }
      } else {
        if (s[i] != '?' && s[i] != '*') {
          cout << s[i];
        }
      }
    }
    if (s[s.length() - 1] != '?' && s[s.length() - 1] != '?')
      cout << s[s.length() - 1] << endl;
    return 0;
  } else {
    long long int xd = k - lmx;
    for (long long int i = 0; i < s.length() - 1; i++) {
      if (s[i] != '?' && s[i] != '*') {
        cout << s[i];
      }
      if (s[i + 1] == '*') {
        for (long long int j = 0; j < xd; j++) {
          cout << s[i];
        }
        xd = 0;
      }
    }
    if (s[s.length() - 1] != '?' && s[s.length() - 1] != '?')
      cout << s[s.length() - 1] << endl;
    return 0;
  }
}
