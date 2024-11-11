#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> mp;
  for (long long i = 0; i < 100001; ++i) mp[i] = 0;
  for (long long i = 0; i < n; ++i) {
    long long first;
    cin >> first;
    mp[first]++;
  }
  long long two = 0, four = 0, six = 0, eight = 0;
  for (auto i = mp.begin(); i != mp.end(); i++) {
    if (i->second >= 8)
      eight++;
    else if (i->second >= 6)
      six++;
    else if (i->second >= 4)
      four++;
    else if (i->second >= 2)
      two++;
  }
  long long q;
  cin >> q;
  while (q--) {
    char ch;
    cin >> ch;
    long long first;
    cin >> first;
    if (ch == '+') {
      if (mp[first] >= 8) {
      } else if (mp[first] == 7) {
        eight++;
        six--;
      } else if (mp[first] == 5) {
        six++;
        four--;
      } else if (mp[first] == 3) {
        four++;
        two--;
      } else if (mp[first] == 1) {
        two++;
      }
      mp[first]++;
    } else {
      if (mp[first] > 8) {
      } else if (mp[first] == 8) {
        eight--;
        six++;
      } else if (mp[first] == 6) {
        six--;
        four++;
      } else if (mp[first] == 4) {
        four--;
        two++;
      } else if (mp[first] == 2) {
        two--;
      }
      mp[first]--;
    }
    bool ex = false;
    if (eight >= 1)
      ex = true;
    else if (six >= 2)
      ex = true;
    else if (four >= 2)
      ex = true;
    else if (six == 1 && (two >= 1 || four >= 1))
      ex = true;
    else if (four == 1 && (two >= 2 || six >= 1))
      ex = true;
    if (ex)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
