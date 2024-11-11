#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 5;
string s;
int pref[NMAX];
int cnt[NMAX];
int main() {
  int N, i, j;
  cin >> s;
  N = s.size();
  if (N == 1) {
    cout << "Just a legend";
    return 0;
  }
  for (i = 1, j = 0; i < N; ++i) {
    if (s[i] == s[j])
      pref[i] = ++j;
    else {
      if (j > 0) {
        j = pref[j - 1];
        i--;
      }
    }
  }
  for (i = 0; i < N; ++i) cnt[pref[i]]++;
  if (pref[N - 1] == 0) {
    cout << "Just a legend";
    return 0;
  } else if (cnt[pref[N - 1]] > 1) {
    for (i = 0; i < pref[N - 1]; ++i) cout << s[i];
    return 0;
  } else {
    j = pref[pref[N - 1] - 1];
    if (j > 1) {
      for (i = 0; i < j; ++i) cout << s[i];
    } else {
      cout << "Just a legend";
    }
    return 0;
  }
}
