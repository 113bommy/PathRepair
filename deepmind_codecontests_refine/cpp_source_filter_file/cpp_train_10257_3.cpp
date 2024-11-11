#include <bits/stdc++.h>
using namespace std;
const int M = 250;
const int N = 3005;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long fact(long long n) {
  long long ret = 1;
  for (int i = 1; i <= n; i++) ret *= i;
  return ret;
}
bool is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  return 0;
}
int n, m, l[N][N], r[N][N], bit[N * 2];
vector<int> ins[N];
string s[N];
void update(int idx, int val) {
  while (idx <= n + m) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int get(int idx) {
  int ret = 0;
  while (idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}
vector<vector<pair<int, int> > > all;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      l[i][j] = s[i][j] == 'z';
      if (j && l[i][j]) l[i][j] += l[i][j - 1];
    }
    for (int j = m - 1; j >= 0; j--) {
      r[i][j] = s[i][j] == 'z';
      if (r[i][j]) r[i][j] += r[i][j + 1];
    }
  }
  for (int k = 0; k < m; k++) {
    int i = 0, j = k;
    vector<pair<int, int> > tmp;
    while (i < n && j >= 0) {
      tmp.push_back(pair<int, int>(i, j));
      i++;
      j--;
    }
    all.push_back(tmp);
  }
  for (int k = 1; k < n; k++) {
    int i = k, j = m - 1;
    vector<pair<int, int> > tmp;
    while (i < n && j >= 0) {
      tmp.push_back(pair<int, int>(i, j));
      i++;
      j--;
    }
    all.push_back(tmp);
  }
  int sum = 0;
  for (int i = 0; i < all.size(); i++) {
    memset(bit, 0, sizeof(bit));
    for (int j = 0; j < all[i].size(); j++) {
      ins[j + 1].clear();
    }
    int prv = 0;
    for (int j = 0; j < all[i].size(); j++) {
      pair<int, int> cur = all[i][j];
      if (s[cur.first][cur.second] == '.') {
        prv = j + 1;
        continue;
      }
      int best = r[cur.first][cur.second];
      int idx = j - best + 1;
      idx++;
      idx = max(prv + 1, idx);
      ins[idx].push_back(j + 1);
    }
    for (int j = 0; j < all[i].size(); j++) {
      for (int k = 0; k < ins[j + 1].size(); k++) {
        update(ins[j + 1][k], 1);
      }
      pair<int, int> cur = all[i][j];
      if (s[cur.first][cur.second] == '.') continue;
      int best = l[cur.first][cur.second];
      sum += get(j + best) - get(j);
    }
  }
  cout << sum;
  return 0;
}
