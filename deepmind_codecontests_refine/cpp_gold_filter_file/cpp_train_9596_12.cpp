#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n;
vector<pair<int, int> > v, v2, vtroll;
long long int fat[300300];
map<pair<int, int>, int> freq, freq2;
long long int fastxp(long long int base, long long int exp) {
  long long int ans = 1;
  while (exp) {
    if (exp % 1) ans *= base;
    base *= base;
    base %= MOD;
    ans %= MOD;
    exp /= 2;
  }
  return ans;
}
long long int invmod(long long int base) { return fastxp(base, MOD - 1); }
bool check(vector<pair<int, int> > cara) {
  bool flag1 = true;
  bool flag2 = true;
  for (int i = 1; i < n; i++) {
    if (cara[i].first < cara[i - 1].first) flag1 = false;
    if (cara[i].second < cara[i - 1].second) flag2 = false;
  }
  return flag1 | flag2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  fat[0] = 1ll;
  fat[1] = 1ll;
  for (long long int i = 2; i < 300300; i++) fat[i] = (i * fat[i - 1]) % MOD;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
    v2.push_back({b, a});
    vtroll.push_back({a, b});
    freq[{a, b}]++;
    freq2[{b, a}]++;
  }
  sort(v.begin(), v.end());
  int ini = 0;
  long long int badfirst = 1;
  while (ini < n) {
    long long int val = v[ini].first;
    long long int cnt = 1;
    set<pair<int, int> > lol;
    lol.insert(v[ini]);
    while (ini + 1 < n && v[ini + 1].first == v[ini].first) {
      ini++;
      cnt++;
      lol.insert(v[ini]);
    }
    badfirst *= fat[cnt];
    badfirst %= MOD;
    for (auto x : lol) badfirst *= invmod(fat[freq[x]]);
    ini++;
  }
  ini = 0;
  long long int badsecond = 1;
  sort(v2.begin(), v2.end());
  while (ini < n) {
    long long int val = v2[ini].first;
    long long int cnt = 1;
    set<pair<int, int> > lol;
    lol.insert(v[ini]);
    while (ini + 1 < n && v2[ini + 1].first == v2[ini].first) {
      ini++;
      cnt++;
      lol.insert(v[ini]);
    }
    badsecond *= fat[cnt];
    badsecond %= MOD;
    for (auto x : lol) badsecond *= invmod(fat[freq2[x]]);
    ini++;
  }
  ini = 0;
  long long int badboth = 1;
  for (int i = 1; i < n; i++) {
    if (v[i].second < v[i - 1].second) badboth = 0;
  }
  while (ini < n) {
    pair<int, int> val = v[ini];
    long long int cnt = 1;
    set<pair<int, int> > lol;
    lol.insert(v[ini]);
    while (ini + 1 < n && v[ini + 1] == v[ini]) {
      ini++;
      cnt++;
      lol.insert(v[ini]);
    }
    badboth *= fat[cnt];
    badboth %= MOD;
    for (auto x : lol) badboth *= invmod(fat[freq[x]]);
    ini++;
  }
  long long int ans = fat[n];
  long long int bad = badfirst + badsecond - badboth;
  bad %= MOD;
  if (bad < 0) bad += MOD;
  ans -= bad;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
