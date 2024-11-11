#include <bits/stdc++.h>
using namespace std;
const unsigned int mod = 1e7 + 7;
const long long int N = 1e5;
map<long long int, char> mp;
bool visit[1000] = {false}, vis[10009] = {false};
vector<long long int> v[1000];
string s[1000], si;
int main() {
  long long int l, ans = 1, n, m, cnt, k = 0, t = 0, z = 0, w = INT_MAX,
                   pre = 1e5, mid, a[29] = {0}, h[29] = {0}, t1, t2, now, r = 0,
                   i = 0, j = 0, flag = 0, temp = 0, e = -1e4, o = 0;
  cin >> n;
  string s;
  for (i = 0; i < 4; i++) {
    cin >> s;
    for (j = 0; j < 4; j++) {
      if (s[i] != '.') h[s[i] - 48]++;
    }
  }
  for (i = 1; i <= 9; i++) {
    if (h[i] > 2 * n) return cout << "NO", 0;
  }
  cout << "YES";
}
