#include <bits/stdc++.h>
using namespace std;
vector<long long int> graph[200005];
long long int vis[200005] = {0};
const long long int inf = 1e18;
const long long int mod = 998244353;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
string alpha = "abcdefghijklmnopqrstuvwxyz";
bool checkPalindrome(string str) {
  long long int t, l, i, j, p;
  string a, b;
  l = str.length();
  a = str.substr(0, l / 2);
  if (l % 2 == 0) {
    b = str.substr(l / 2, l / 2);
    reverse(b.begin(), b.end());
    if (a == b) return true;
    return false;
  } else {
    b = str.substr(l / 2 + 1, l / 2);
    reverse(b.begin(), b.end());
    if (a == b) return true;
    return false;
  }
}
void dfs(long long int node) {
  vis[node] = 1;
  for (auto u : graph[node]) {
    if (!vis[u]) dfs(u);
  }
}
bool comp(string str1, string str2) { return str1 + str2 < str2 + str1; }
long long int prime[100005] = {0};
void seive(long long int n) {
  long long int i, j, p, k, c;
  prime[0] = prime[1] = 1;
  for (i = 2; i * i <= n; i++) {
    for (j = i * i; j <= n; j += i) prime[j] = 1;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int t, n, p, l, i, j, cnt, curr = 0;
  string str;
  cin >> str;
  unordered_set<char> st;
  st.insert('a'), st.insert('e'), st.insert('i'), st.insert('u'),
      st.insert('o');
  l = str.length();
  for (i = 0; i < l; i++) {
    if (st.find(str[i]) != st.end()) curr = i + 3;
    if (i < curr || i < 2) {
      cout << str[i];
      continue;
    } else {
      if (str[i] == str[i - 1] && str[i - 1] == str[i - 2])
        cout << str[i];
      else {
        cout << " " << str[i];
        curr = i + 3;
      }
    }
  }
  cout << endl;
}
