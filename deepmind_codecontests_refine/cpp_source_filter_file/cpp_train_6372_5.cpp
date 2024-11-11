#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long int inf64 = 1e18;
const int mod = inf + 7;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s += "0";
  vector<char> v(k);
  for (int i = 0; i < k; i++) cin >> v[i];
  ;
  long long ans = 0;
  int c = 0;
  for (int i = 0; i < s.size() + 1; i++) {
    if (find((v).begin(), (v).end(), s[i]) == v.end()) {
      ans += c * (c + 1) / 2;
      c = 0;
    } else
      c++;
  }
  cout << ans << endl;
}
