#include <bits/stdc++.h>
const int MAXN = 1e6;
const int mod = 1e9 + 7;
using namespace std;
int const base = 357;
long long getHash(string second) {
  long long HashValue = 0;
  for (int i = 0; i < second.size(); i++) {
    HashValue = (HashValue * base + second[i]) % mod;
  }
  return HashValue;
}
long long first[MAXN] = {1};
void init() {
  first[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    first[i] = first[i - 1] * base % mod;
  }
}
bool check(string keys, set<long long> &container) {
  long long h = getHash(keys);
  int len = keys.size();
  for (int i = 0; i < len; i++) {
    for (int c = 'a'; c < 'c' + 1; c++) {
      if (c == keys[i]) continue;
      long long newhash =
          (((c - keys[i]) * first[len - i - 1] % mod) + mod + h) % mod;
      if (container.find(newhash) != container.end()) {
        return true;
      }
    }
  }
  return false;
}
void solution_AC() {
  int n, q;
  cin >> n >> q;
  set<long long> container;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    long long ans = getHash(second);
    container.insert(ans);
  }
  while (q--) {
    string query;
    cin >> query;
    if (check(query, container))
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
}
int main() {
  init();
  cin.tie();
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  ;
  int test = 1;
  while (test--) {
    solution_AC();
    cout << '\n';
  }
  return 0;
}
