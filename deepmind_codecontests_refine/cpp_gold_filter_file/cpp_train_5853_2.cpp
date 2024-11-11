#include <bits/stdc++.h>
using namespace std;
int bPow(int v, int u, int mod) {
  if (!u) return 1;
  int res = bPow(v, u / 2, mod);
  res = (res * 1ll * res) % mod;
  if (u & 1) res = (res * 1ll * v) % mod;
  return res;
}
bool fb(long long x) { return 0; }
int bSearch(int l, int r) {
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (fb(m))
      l = m;
    else
      r = m;
  }
  if (fb(l + 1)) l++;
  if (!fb(l)) l = 0;
  return l;
}
void faster() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  if (0) {
    freopen(
        "a"
        ".in",
        "r", stdin);
    freopen(
        "a"
        ".out",
        "w", stdout);
  }
}
vector<int> prime;
bool notprime[1000010];
void resh() {
  int n = 1000010 - 10;
  for (int i = 2; i < n; i++)
    if (!notprime[i]) {
      prime.push_back(i);
      for (int j = i; j < n; j += i) notprime[j] = 1;
    }
}
int is_comp(long long p) {
  for (int i = 0; prime[i] * 1ll * prime[i] <= p; i++) {
    if (p % prime[i] == 0) return prime[i];
  }
  return 0;
}
bool is_prime(long long p) {
  for (int i = 0; prime[i] * 1ll * prime[i] <= p; i++) {
    if (p % prime[i] == 0) return 0;
  }
  return 1;
}
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (!a) return b;
  return gcd(b % a, a);
}
int n, m, p;
string s, c;
vector<string> v[4];
void ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  cout.flush();
  m = (r - l + 1) * (r - l + 2) / 2;
  for (int i = 0; i < m; i++) {
    cin >> c;
    sort(c.begin(), c.end());
    v[p].push_back(c);
  }
}
void print() {
  cout << "! " << s << endl;
  cout.flush();
}
int w[33], W[33], cnt[33], q[33];
void ch() {
  for (int j = 0; j < 26; j++) w[j] = 0;
}
void fs(string& a) {
  for (int i = 0; i < a.size(); i++) w[a[i] - 'a']++;
}
void half() {
  map<string, int> ma;
  for (int i = 0; i < v[0].size(); i++) ma[v[0][i]]++;
  for (int i = 0; i < v[1].size(); i++) ma[v[1][i]]--;
  vector<string> temp[111];
  for (auto& x : ma)
    for (int i = 0; i < x.second; i++)
      temp[x.first.size() - 1].push_back(x.first);
  m = n - n / 2;
  for (int i = 0; i < m; i++) {
    string t = temp[i][0];
    for (int j = 0; j <= i; j++) {
      w[t[j] - 'a']--;
      if (w[t[j] - 'a'] < 0) {
        s += t[j];
        break;
      }
    }
    ch();
    for (int j = 0; j < s.size(); j++) w[s[j] - 'a']++;
  }
}
void solve() {
  half();
  vector<string> temp[111];
  for (int i = 0; i < v[2].size(); i++)
    temp[v[2][i].size() - 1].push_back(v[2][i]);
  c = temp[n - 1][0];
  for (int i = 0; i < c.size(); i++) W[c[i] - 'a']++;
  string t = "", cur = "";
  m = n - n / 2 - 1;
  int l = 0;
  for (int i = n - 2; i >= m; i--) {
    ch();
    cnt[s[l] - 'a']++;
    for (int j = 0; j < temp[i].size(); j++) fs(temp[i][j]);
    for (int j = 0; j < 26; j++) q[j] = (l + 2) * W[j] - cnt[j];
    for (int j = 0; j < 26; j++)
      if (w[j] < q[j]) cur = j + 'a';
    cnt[cur[0] - 'a']++;
    t += cur;
    l++;
    for (int j = 0; j < l; j++) {
      cnt[s[j] - 'a']++;
      cnt[t[j] - 'a']++;
    }
  }
  reverse(t.begin(), t.end());
  s += t;
}
int main() {
  faster();
  cin >> n;
  if (n < 4) {
    for (int i = 1; i <= n; i++) {
      ask(i, i);
      s += c;
    }
    print();
    return 0;
  }
  ask(1, n - n / 2);
  p++;
  ask(2, n - n / 2);
  p++;
  ask(1, n);
  solve();
  print();
  return 0;
}
