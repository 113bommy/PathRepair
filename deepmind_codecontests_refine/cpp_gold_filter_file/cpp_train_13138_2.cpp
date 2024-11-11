#include <bits/stdc++.h>
using namespace std;
int lim = 1000000;
int mod = 1000000000 + 7;
int inf = 1000000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  const string t = "Just a legend";
  int n = (int)s.length();
  vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
  if (pi[n - 1] == 0) {
    cout << t;
  } else {
    int p = 0;
    for (int i = 1; i < n - 1; i++) {
      if (pi[i] == pi[n - 1]) {
        p = 1;
        break;
      }
    }
    if (p) {
      for (int i = 0; i < pi[n - 1]; i++) {
        cout << s[i];
      }
    } else {
      if (pi[pi[n - 1] - 1] == 0) {
        cout << t;
      } else {
        int p1 = 0;
        for (int i = 1; i < n - 1; i++) {
          if (pi[i] == pi[pi[n - 1] - 1]) {
            p1 = 1;
            break;
          }
        }
        if (p1) {
          for (int i = 0; i < pi[pi[n - 1] - 1]; i++) {
            cout << s[i];
          }
        } else {
          cout << t;
        }
      }
    }
  }
}
