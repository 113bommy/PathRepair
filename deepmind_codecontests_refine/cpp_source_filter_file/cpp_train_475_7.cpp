#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
  string s[] = {"Anka",   "Chapay", "Cleo",       "Troll",
                "Dracul", "Snowy",  "Hexadecimal"};
  map<string, int> m;
  for (long i = 0; i < 7; i++) m[s[i]] = i;
  int l[7][7], n;
  cin >> n;
  string x, y, z;
  for (long i = 0; i < n; i++) {
    cin >> x >> y >> z;
    l[m[x]][m[z]]++;
  }
  long a, b, c, mx, mn;
  cin >> a >> b >> c;
  int p = 3 * 3 * 3 * 3 * 3 * 3 * 3, tans;
  long min1 = 2e9 + 1;
  int max2 = 0;
  for (long i = 1; i < p; i++) {
    int temp = i;
    set<int> st;
    vector<int> v;
    long count[3] = {};
    for (long j = 0; j < 7; j++) {
      st.insert(temp % 3);
      count[temp % 3]++;
      v.push_back(temp % 3);
      temp /= 3;
    }
    if (st.size() < 3) {
      continue;
    }
    mx = max(c / count[2], max(a / count[0], b / count[1]));
    mn = min(c / count[2], min(a / count[0], b / count[1]));
    if (mx - mn <= min1) {
      tans = 0;
      for (long j = 0; j < 7; j++) {
        for (long k = 0; k < 7; k++)
          if (v[j] == v[k] && l[j][k] == 1) tans++;
      }
      if (mx - mn < min1)
        max2 = tans;
      else
        max2 = max(max2, tans);
      min1 = min(min1, mx - mn);
    }
  }
  cout << min1 << " " << max2 << endl;
}
