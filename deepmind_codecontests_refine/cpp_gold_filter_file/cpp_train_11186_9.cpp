#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int trie[2000000][26];
int canwin[2000001];
int canlose[2000001];
int next1 = 1;
void insert(string s) {
  long long sz = s.size();
  int v = 0;
  for (long long i = 0; i < sz; i++) {
    long long cur = s[i] - 'a';
    if (trie[v][cur] == -1) {
      trie[v][cur] = next1++;
    }
    v = trie[v][cur];
  }
}
long long dfs(long long v) {
  long long store = 0;
  for (long long i = 0; i < 26; i++) {
    if (trie[v][i] != -1) {
      if (dfs(trie[v][i]) == 0) store = 1;
    }
  }
  canwin[v] = store;
  return store;
}
long long dfs2(long long v) {
  long long store = 0;
  bool check = false;
  for (long long i = 0; i < 26; i++) {
    if (trie[v][i] != -1) {
      check = true;
      if (dfs2(trie[v][i]) == 0) store = 1;
    }
  }
  if (!check) store = 1;
  canlose[v] = store;
  return store;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(trie, -1, sizeof(trie));
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s);
  }
  long long st1 = dfs(0);
  long long st2 = dfs2(0);
  if (st1 && st2) {
    cout << "First";
  } else if (st1) {
    if (k % 2) {
      cout << "First";
    } else {
      cout << "Second";
    }
  } else {
    cout << "Second";
  }
  return 0;
}
