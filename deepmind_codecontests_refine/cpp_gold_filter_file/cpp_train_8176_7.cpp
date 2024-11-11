#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long len = s.size(), f = 0, p = 0;
  long long cnt[26];
  for (long long i = 0; i <= len - 26; i++) {
    long long c = 0;
    for (long long j = 0; j < 26; j++) cnt[j] = 0;
    for (long long j = i; j < i + 26; j++) {
      if (s[j] != '?') cnt[s[j] - 'A'] += 1;
    }
    for (long long j = 0; j < 26; j++) {
      if (cnt[j] > 1) c = 1;
    }
    if (!c) {
      f = 1;
      break;
    }
  }
  if (!f) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < len; i++) {
    long long c = 0;
    for (long long j = 0; j < 26; j++) cnt[j] = 0;
    for (long long j = i; j < i + 26; j++) {
      if (s[j] != '?') cnt[s[j] - 'A'] += 1;
    }
    for (long long j = 0; j < 26; j++) {
      if (cnt[j] > 1) c = 1;
    }
    if (!c && !p) {
      for (long long j = i; j < i + 26; j++) {
        if (s[j] == '?') {
          for (long long k = 0; k < 26; k++) {
            if (cnt[k] == 0) {
              char ch = k + 'A';
              cout << ch;
              cnt[k] = 1;
              break;
            }
          }
        } else
          cout << s[j];
      }
      i += 25;
      p = 1;
    } else {
      if (s[i] == '?')
        cout << 'A';
      else
        cout << s[i];
    }
  }
}
