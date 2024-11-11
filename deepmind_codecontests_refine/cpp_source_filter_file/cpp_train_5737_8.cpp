#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, v[500010], m, a, b, x, y, h, w, l, p, ans, numitor, aux,
    mini, maxi, sum, poz, val[600010], arbint[600010], t, z, d, q, r;
pair<long long, long long> stanga[300010], dreapta[300010];
string s1, s2, second;
const long long int offset = 200001;
char c[1000010];
long double dAns, distmin, distmax;
char matrice[510][510];
vector<int> G[500010];
vector<int> redE[200010];
queue<int> Q;
stack<int> stk;
map<long long, long long> mip;
set<int> sit;
map<string, string> miip;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> stanga[i].first >> stanga[i].second;
    dreapta[i] = stanga[i];
  }
  for (int i = 2; i <= n; i++) {
    stanga[i].first = max(stanga[i].first, stanga[i - 1].first);
    stanga[i].second = min(stanga[i].second, stanga[i - 1].second);
  }
  for (int i = n - 1; i >= 1; i--) {
    dreapta[i].first = max(dreapta[i].first, dreapta[i + 1].first);
    dreapta[i].second = min(dreapta[i].second, dreapta[i + 1].second);
  }
  ans = max(ans, stanga[n - 1].second - stanga[n - 1].first);
  ans = max(ans, dreapta[1].second - dreapta[1].first);
  for (int i = 2; i < n; i++) {
    a = max(stanga[i - 1].first, dreapta[i + 1].first);
    b = min(stanga[i - 1].second, dreapta[i + 1].second);
    ans = max(ans, b - a);
  }
  cout << ans;
  return 0;
}
