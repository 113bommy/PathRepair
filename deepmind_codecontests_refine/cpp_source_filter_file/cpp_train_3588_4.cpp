#include <bits/stdc++.h>
using namespace std;
template <typename T>
string toString(T Number) {
  stringstream st;
  st << Number;
  return st.str();
}
int stringconvert(string s) {
  int p;
  istringstream st(s);
  st >> p;
  return p;
}
long long bigmod(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = ((res % m) * (a % m)) % m;
    }
    a = ((a % m) * (a % m)) % m;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long a, long long m) { return bigmod(a, m - 2, m); }
int main() {
  ios_base::sync_with_stdio(0);
  ;
  string s1, s2, s;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  map<string, string> team;
  team["h"] = s1;
  team["a"] = s2;
  map<string, map<int, int> > mp;
  while (n--) {
    int time, pn;
    string card;
    cin >> time >> s >> pn >> card;
    if (card == "y") {
      mp[s][pn]++;
      if (mp[s][pn] == 2) {
        cout << team[s] << " " << pn << " " << time << endl;
        mp[s][pn] = -100;
      }
    } else {
      if (mp[s][pn] != -100) {
        cout << team[s] << " " << pn << " " << time << endl;
        mp[s][pn] = -100;
      }
    }
  }
  return 0;
}
