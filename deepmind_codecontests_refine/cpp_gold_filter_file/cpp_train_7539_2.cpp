#include <bits/stdc++.h>
using namespace std;
long long suf(long long a) { return (a * (a + 1)) / 2; }
const long long OO = 1e6 + 10, S = 1e6 + 10;
vector<vector<int> > adj, can;
bool OK;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
int main() {
  int n, m, k;
  string a, b;
  while (cin >> a >> b) {
    vector<int> q(26), q1(26);
    for (int i = 0; i < a.size(); i++) q[a[i] - 'a']++;
    for (int i = 0; i < b.size(); i++) q1[b[i] - 'a']++;
    OK = false;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (q[i] <= q1[i])
        ans += q[i];
      else
        ans += q1[i];
      if ((q1[i] != 0) && (q[i] == 0)) OK = true;
    }
    if (OK)
      cout << "-1" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
