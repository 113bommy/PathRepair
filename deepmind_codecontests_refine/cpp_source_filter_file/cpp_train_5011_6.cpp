#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void readFile() {}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a;
    a *= a;
    b = b >> 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readFile();
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s_copy = s;
  int ch1 = 0, ch2 = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == s[i - 1]) {
      ch1++;
      if (s[i - 1] == 'B' && s[i + 1] == 'G')
        s[i] = 'R';
      else if (s[i - 1] == 'B' && s[i + 1] == 'R')
        s[i] = 'G';
      else if (s[i - 1] == 'B' && s[i + 1] == 'B')
        s[i] = 'R';
      else if (s[i - 1] == 'G' && s[i + 1] == 'R')
        s[i] = 'B';
      else if (s[i - 1] == 'G' && s[i + 1] == 'G')
        s[i] = 'B';
      else if (s[i - 1] == 'G' && s[i + 1] == 'B')
        s[i] = 'R';
      else if (s[i - 1] == 'R' && s[i + 1] == 'R')
        s[i] = 'B';
      else if (s[i - 1] == 'R' && s[i + 1] == 'G')
        s[i] = 'B';
      else if (s[i - 1] == 'R' && s[i + 1] == 'B')
        s[i] = 'G';
    }
  }
  if (s[n - 1] == s[n - 2]) {
    ch1++;
    if (s[n - 1] == 'R')
      s[n - 2] = 'G';
    else if (s[n - 1] == 'G')
      s[n - 2] = 'B';
    else if (s[n - 1] == 'B')
      s[n - 2] = 'R';
  }
  string ans = s;
  reverse(s_copy.begin(), s_copy.end());
  s = s_copy;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == s[i - 1]) {
      ch2++;
      if (s[i - 1] == 'B' && s[i + 1] == 'G')
        s[i] = 'R';
      else if (s[i - 1] == 'B' && s[i + 1] == 'R')
        s[i] = 'G';
      else if (s[i - 1] == 'B' && s[i + 1] == 'B')
        s[i] = 'R';
      else if (s[i - 1] == 'G' && s[i + 1] == 'R')
        s[i] = 'B';
      else if (s[i - 1] == 'G' && s[i + 1] == 'G')
        s[i] = 'B';
      else if (s[i - 1] == 'G' && s[i + 1] == 'B')
        s[i] = 'R';
      else if (s[i - 1] == 'R' && s[i + 1] == 'R')
        s[i] = 'B';
      else if (s[i - 1] == 'R' && s[i + 1] == 'G')
        s[i] = 'B';
      else if (s[i - 1] == 'R' && s[i + 1] == 'B')
        s[i] = 'G';
    }
  }
  if (s[n - 1] == s[n - 2]) {
    ch2++;
    if (s[n - 1] == 'R')
      s[n - 2] = 'G';
    else if (s[n - 1] == 'G')
      s[n - 2] = 'B';
    else if (s[n - 1] == 'B')
      s[n - 2] = 'R';
  }
  if (ch1 < ch2 && ch1 != 0) {
    cout << ch1 << '\n';
    cout << ans;
  } else {
    cout << ch2 << '\n';
    reverse(s.begin(), s.end());
    cout << s << '\n';
  }
}
