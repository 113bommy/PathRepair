#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1e8;
string itos(long long n) {
  string res = "";
  while (n > 0) {
    int d = n % 10;
    res += (char)(d + '0');
    n /= 10;
  }
  reverse((res).begin(), (res).end());
  return res;
}
int main() {
  string s;
  cin >> s;
  long long n = s.size();
  vector<bool> appears(30, false);
  for (long long i = 0; i < n; i++)
    if (isupper(s[i])) appears[s[i] - 'A'] = true;
  long long unknown = 0;
  for (long long i = 0; i < n; i++)
    if (s[i] == '?') unknown++;
  long long lettersThatAppear = 0;
  for (long long i = 0; i < 30; i++)
    if (appears[i]) lettersThatAppear++;
  if (isupper(s[0])) {
    long long a = 9;
    for (long long i = 0; i < lettersThatAppear - 1; i++) {
      a *= (9 - i);
    }
    string res = itos(a);
    string zeros(unknown, '0');
    res = res + zeros;
    cout << res << endl;
  } else if (s[0] == '?') {
    long long a = 9;
    for (long long i = 0; i < lettersThatAppear - 1; i++) {
      a *= (10 - i);
    }
    string res = itos(a);
    string zeros(unknown - 1, '0');
    res = res + zeros;
    cout << res << endl;
  } else {
    long long a = 1;
    for (long long i = 0; i < lettersThatAppear; i++) {
      a *= (10 - i);
    }
    string res = itos(a);
    string zeros(unknown, '0');
    res = res + zeros;
    cout << res << endl;
  }
  return 0;
}
