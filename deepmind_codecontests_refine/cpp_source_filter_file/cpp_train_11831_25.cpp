#include <bits/stdc++.h>
using namespace std;
void output() {
  string s;
  cin >> s;
  long long len = s.size();
  long long ans = 0;
  for (long long i = (0); i < (len); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '0' || s[i] == '2' || s[i] == '4' ||
        s[i] == '6' || s[i] == '8') {
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = (0); i < (t); i++) {
    output();
  }
  return 0;
}
