#include <bits/stdc++.h>
using namespace std;
map<string, long long> mp;
int main() {
  int n;
  cin >> n;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    string tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  cout << (mp["UL"] + mp["DR"] + mp["ULDR"] + 1) *
              (mp["UR"] + mp["DL"] + mp["ULDR"] + 1);
  return 0;
}
