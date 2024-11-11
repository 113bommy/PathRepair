#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> ws;
  ;
  cin >> s;
  if (k % 2) {
    cout << "NO"
         << "\n";
    return;
  }
  if (count(s.begin(), s.end(), '?') == n) {
    cout << "YES"
         << "\n";
    return;
  }
  for (long long int i = 0; i < (n - k); i++) {
    if (s[i] == '?') continue;
    if (s[i + k] == '?') {
      s[i + k] = s[i];
      continue;
    }
    if (s[i] != s[i + k]) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  for (long long int i = n - 1; i >= (k); i--) {
    if (s[i] == '?') continue;
    if (s[i - k] == '?') {
      s[i - k] = s[i];
      continue;
    }
    if (s[i] != s[i - k]) {
      cout << "NO"
           << "\n";
      break;
    }
  }
  string temp = s.substr(0, k);
  long long cnt1 = count(temp.begin(), temp.end(), '1');
  long long cnt0 = count(temp.begin(), temp.end(), '0');
  for (long long int i = 0; i < (k); i++) {
    if (cnt1 < k / 2 && s[i] == '?') {
      s[i] = '1';
      cnt1++;
    } else if (cnt0 < k / 2 && s[i] == '?') {
      s[i] = '0';
      cnt0++;
    }
  }
  if (cnt1 != cnt0) {
    cout << "NO"
         << "\n";
    return;
  }
  for (long long int i = 0; i < (n - k); i++) {
    if (s[i + k] == '?')
      s[i + k] = s[i];
    else if (s[i] != s[i + k]) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
  return;
}
void tsolve() {
  int t;
  cin >> t;
  while (t--) solve();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tsolve();
}
