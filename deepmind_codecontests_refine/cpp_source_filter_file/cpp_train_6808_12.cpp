#include <bits/stdc++.h>
using namespace std;
long long int finddiv(long long int n) {
  vector<long long int> div;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (i == n / i)
        div.push_back(i);
      else {
        div.push_back(i);
        div.push_back(n / i);
      }
    }
  }
  sort(div.begin(), div.end());
  long long int sz = div.size();
  return sz;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt = 1;
  while (tt--) {
    string s;
    cin >> s;
    string ans = "";
    long long int len = s.size();
    for (long long int i = 0; i <= len - 1; i++) {
      if (s[i] == '.')
        ans += '0';
      else {
        if (s[i] == '.')
          ans += '1';
        else
          ans += '2';
        i++;
      }
    }
    cout << ans;
  }
  return 0;
}
