#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt1, cnt2, cnt3;
long long cnt1a, cnt2a;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  long long n = s.size();
  for (long long i = 0; i < n; i++) {
    if (s[i] == '(') cnt1++;
    if (s[i] == ')') cnt2++;
    if (s[i] == '#') cnt3++;
  }
  if (cnt1 - cnt2 <= 0) {
    cout << -1;
    return 0;
  }
  if ((cnt1 - cnt2) / cnt3 < 1) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < cnt3 - 1; i++) {
    if (s[i] == '(') cnt1a++;
    if (s[i] == ')') cnt2a++;
    if (cnt1a > cnt2a) {
      cout << -1;
      return 0;
    }
    if (s[i] == '#') {
      if (cnt1a - cnt2a <= 0) {
        cout << -1;
        return 0;
      }
      break;
    }
  }
  cnt1a = cnt2a = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '(') cnt1a++;
    if (s[i] == ')') cnt2a++;
    if (cnt1a > cnt2a) {
      cout << -1;
      return 0;
    }
    if (s[i] == '#') break;
  }
  for (long long i = 0; i < cnt3 - 1; i++) v.push_back(1);
  v.push_back(cnt1 - cnt2 - (cnt3 - 1));
  for (long long i = 0; i < v.size(); i++) cout << v[i] << '\n';
  return 0;
}
