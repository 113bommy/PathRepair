#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e9 + 7;
const long long int mod = 998244353;
long long int maxi(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
long long int mini(long long int a, long long int b) {
  if (a >= b) return b;
  return a;
}
string getst(string s, long long int st, long long int en) {
  string ans = "";
  for (long long int i = st; i <= en - 1; i++) ans += s[i];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int n;
  cin >> n;
  string s;
  map<string, long long int> mark, sub[70005];
  for (long long int l = 0; l < n; l++) {
    cin >> s;
    for (long long int i = 0; i <= 8; i++) {
      string d = "";
      for (long long int j = i; j <= 8; j++) {
        d += s[j];
        mark[d]++;
        sub[l][d]++;
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    string fans = "123456789";
    for (auto x : sub[i]) {
      if (x.second == mark[x.first] && x.first.size() <= fans.size())
        fans = x.first;
    }
    cout << fans << "\n";
  }
  return 0;
}
