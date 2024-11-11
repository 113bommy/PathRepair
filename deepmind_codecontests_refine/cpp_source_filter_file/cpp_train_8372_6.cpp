#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const double EPS = 1E-9;
const long long INF = 2 * (1e+9) + 1;
const int NMAX = 1000000;
const int MOD = (1e+9) + 7;
int n, m, k;
string s;
long long cc1[1000100];
int main() {
  ios_base::sync_with_stdio(0);
  string tmp;
  cin >> tmp;
  s += '@';
  s += tmp;
  s += '_';
  long long ans = 0, pr1 = 0;
  set<int> c1, c2, c3, c4;
  for (int i = 0; i < ((long long)(s).size()); ++i) {
    if (isalpha(s[i]))
      cc1[i] = 1 + pr1;
    else
      cc1[i] = pr1;
    pr1 = cc1[i];
    if (s[i] == '@' || s[i] == '.') c1.insert(i);
    if (s[i] == '@' || s[i] == '_' || s[i] == '.') c3.insert(i);
    if (s[i] == '.') c2.insert(i);
    if (!isalpha(s[i])) c4.insert(i);
  }
  for (auto it = c1.begin(); it != c1.end(); it++) {
    int idx1 = *it;
    auto it2 = c1.upper_bound(idx1);
    if (it2 == c1.end()) break;
    int idx2 = *it2;
    if (s[idx2] == '.') continue;
    auto it3 = c2.upper_bound(idx2);
    if (it3 == c2.end()) break;
    int idx3 = *it3;
    if (idx3 == idx2) continue;
    auto check = c3.upper_bound(idx2);
    if (*check != idx3) continue;
    auto it4 = c4.upper_bound(idx3);
    if (it4 == c4.end()) break;
    int idx4 = *it4;
    ans += (cc1[idx2] - cc1[idx1]) * (cc1[idx4] - cc1[idx3]);
  }
  cout << ans;
}
