#include <bits/stdc++.h>
using namespace std;
long long pre[1000005], rep[1000005];
int main() {
  string s;
  long long a, b;
  cin >> s;
  cin >> a >> b;
  pre[0] = (s[0] - '0') % a;
  for (int i = 1; i <= s.length() - 1; i++) {
    pre[i] = (pre[i - 1] * 10 % a + (s[i] - '0') % a) % a;
  }
  long long tmp = 10;
  rep[s.length() - 1] = (s[s.length() - 1] - '0') % b;
  for (int i = s.length() - 2; i >= 0; i--) {
    rep[i] = ((s[i] - '0') * tmp % b + rep[i + 1] % b) % b;
    tmp = tmp * 10 % b;
  }
  int pos = -1;
  for (int i = 0; i < s.length() - 1; i++) {
    if (pre[i] == 0 && rep[i + 1] == 0 && s[i + 1] != '0') {
      pos = i;
      break;
    }
  }
  if (pos == -1)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i <= pos; i++) {
      cout << s[i];
    }
    cout << endl;
    for (int i = pos + 1; i < s.length(); i++) {
      cout << s[i];
    }
  }
}
