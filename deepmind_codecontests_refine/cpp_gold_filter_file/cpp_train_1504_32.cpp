#include <bits/stdc++.h>
int scan() {
  int noRead = 0;
  char p = getchar();
  for (; p < 33;) {
    p = getchar();
  }
  while (p > 32) {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p = getchar();
  }
  return noRead;
}
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int minn = -2000000000;
  int maxx = 2000000000;
  while (n--) {
    string pat;
    cin >> pat;
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    if (pat.compare("<") == 0) {
      if (ans.compare("Y") == 0) {
        if (maxx > n - 1) maxx = n - 1;
      }
      if (ans.compare("N") == 0) {
        if (minn < n) minn = n;
      }
    }
    if (pat.compare("<=") == 0) {
      if (ans.compare("Y") == 0) {
        if (maxx > n) maxx = n;
      }
      if (ans.compare("N") == 0) {
        if (minn < n + 1) minn = n + 1;
      }
    }
    if (pat.compare(">") == 0) {
      if (ans.compare("Y") == 0) {
        if (minn < n + 1) minn = n + 1;
      }
      if (ans.compare("N") == 0) {
        if (maxx > n) maxx = n;
      }
    }
    if (pat.compare(">=") == 0) {
      if (ans.compare("Y") == 0) {
        if (minn < n) minn = n;
      }
      if (ans.compare("N") == 0) {
        if (maxx > n - 1) maxx = n - 1;
      }
    }
  }
  if ((minn > maxx) || (minn == -2000000000 && maxx == 2000000000))
    cout << "Impossible";
  else
    cout << min(maxx, minn);
  return 0;
}
