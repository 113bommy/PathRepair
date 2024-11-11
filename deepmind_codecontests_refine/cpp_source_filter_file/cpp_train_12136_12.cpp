#include <bits/stdc++.h>
using namespace std;
long long N = 500005;
long long MAX = 9223372036854775807;
long long MOD = 1000000007;
long long nbr;
bool visited[200005];
vector<long long> mp[200005];
vector<long long> dist;
vector<long long> UI(2 * 1e5 + 5, 0);
void dfs(long long s) {
  visited[s] = true;
  nbr++;
  dist[s]++;
  for (int i = 0; i < mp[s].size(); i++) {
    if (visited[mp[s][i]] == false) {
      dist[mp[s][i]] = dist[s];
      dfs(mp[s][i]);
      UI[s] += UI[mp[s][i]] + 1;
    }
  }
}
bool sorti(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second > b.second;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  string ch;
  cin >> ch;
  string res = "";
  for (int i = 0; i < n; i++) res += 'a';
  long long l = n / 2;
  long long s = n / 2 - 1;
  long long j = n / 2 + 1;
  if (n % 2 == 1) {
    res[l] = ch[0];
    for (int i = 1; i < ch.size(); i++) {
      if (i % 2 == 1) {
        if (s != -1) res[s] = ch[i];
        s--;
      }
      if (i % 2 == 0) {
        if (j != n) res[j] = ch[i];
        j++;
      }
    }
    cout << res;
  }
  if (n % 2 == 0) {
    res[l - 1] = ch[0];
    s--;
    j--;
    for (int i = 1; i < ch.size(); i++) {
      if (i == ch.size() - 1) {
        res[i] = ch[i];
        continue;
      }
      if (i % 2 == 0) {
        if (j != n) res[j] = ch[i];
        j++;
      }
      if (i % 2 == 1) {
        if (s != -1) res[s] = ch[i];
        s--;
      }
    }
    cout << res;
  }
}
