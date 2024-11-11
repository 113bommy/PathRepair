#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long t, x, len, afterx, tempafterx, templen, tempcnt;
string str;
vector<char> v1;
void solve() {
  v1.clear();
  afterx = 0;
  cin >> x;
  cin >> str;
  len = str.size();
  for (int i = 0; i < min(x + 1, len); i++) {
    v1.push_back(str[i]);
  }
  afterx += len - min(x + 1, len);
  for (int i = 0; i < x; i++) {
    templen = v1.size();
    tempcnt = v1[i] - '1';
    while (tempcnt--) {
      for (int j = i + 1; j < templen; j++) {
        if (v1.size() == x + 1) {
          tempafterx = (afterx + templen - j) % MOD;
          if (tempcnt != 0)
            tempafterx = (tempafterx + (templen + afterx - i - 1) % MOD) % MOD;
          afterx = (afterx + tempafterx) % MOD;
          tempcnt = 0;
          break;
        } else
          v1.push_back(v1[j]);
      }
    }
  }
  cout << (v1.size() + afterx) % MOD << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
