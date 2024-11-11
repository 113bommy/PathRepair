#include <bits/stdc++.h>
using namespace std;
void output() {
  string s;
  cin >> s;
  long long len = s.size();
  long long ans = 0;
  for (long long i = (0); i < (len); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '1' || s[i] == '3' || s[i] == '5' ||
        s[i] == '7' || s[i] == '9') {
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
