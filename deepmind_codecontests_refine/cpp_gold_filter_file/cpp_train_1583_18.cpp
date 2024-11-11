#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool isPrime[N], vst[N];
int frq[26];
vector<int> adj[N];
vector<int> cc;
vector<vector<int>> vcc;
void dfs(int u) {
  cc.push_back(u);
  vst[u] = 1;
  for (auto v : adj[u]) {
    if (!vst[v]) dfs(v);
  }
}
bool cmp(vector<int> s, vector<int> f) {
  return (int)(s.size()) > (int)(f.size());
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  for (auto i : s) {
    frq[i - 'a']++;
  }
  isPrime[0] = isPrime[1] = 1;
  for (int i = 2; i <= (int)(s.size()); i++) {
    if (isPrime[i]) continue;
    for (int j = 2 * i; j <= (int)(s.size()); j += i) {
      isPrime[j] = 1;
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
  for (int i = 1; i <= (int)(s.size()); i++) {
    if (!isPrime[i] && !vst[i]) {
      cc.clear();
      dfs(i);
      vcc.push_back(cc);
    }
  }
  sort(vcc.begin(), vcc.end(), cmp);
  vector<char> out((int)(s.size()) + 2);
  for (auto i : vcc) {
    int siz = (int)(i.size());
    int mn = (int)(s.size()) + 1;
    int ch = 26;
    for (int j = 0; j < 26; j++) {
      if (frq[j] >= siz && frq[j] < mn) {
        mn = frq[j];
        ch = j;
      }
    }
    if (ch == 26) {
      return cout << "NO\n", 0;
    }
    frq[ch] -= siz;
    for (auto j : i) {
      out[j] = ch + 'a';
    }
  }
  for (int i = 1; i <= (int)(s.size()); i++) {
    for (int j = 0; j < 26; j++) {
      if (frq[j]) {
        frq[j]--;
        out[i] = j + 'a';
        break;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= (int)(s.size()); i++) cout << out[i];
}
