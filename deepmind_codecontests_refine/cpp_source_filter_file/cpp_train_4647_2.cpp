#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 69;
long long B = 237;
long long M = 1e9 + 7;
bool used[MAXN];
string a[MAXN];
vector<pair<int, int>> cnt[30];
int cn[200][30];
int kek[30];
unordered_map<long long, int> q;
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    if (a[i].size() > 26) {
      cout << "NO";
      return 0;
    }
    int d = a[i].size();
    for (int j = 0; j < d; ++j) {
      long long h = 0;
      for (int k = j; k < d; ++k) {
        h = (h * B) % M + a[i][k] - 'a' + 1;
        if (j == 0 && k == d - 1) continue;
        q[h]++;
      }
    }
  }
  vector<string> b;
  for (int i = 0; i < n; ++i) {
    long long h = 0;
    for (int k = 0; k < a[i].size(); ++k) {
      h = (h * B) % M + a[i][k] - 'a' + 1;
    }
    if (!q[h]) b.push_back(a[i]);
  }
  vector<string> cc = b;
  n = b.size();
  if (n > 53) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < b[i].size(); ++j) {
      int c = b[i][j] - 'a';
      cnt[c].push_back({i, j});
      cn[i][c]++;
      kek[c]++;
    }
  }
  while (1) {
    n = b.size();
    bool ok = 0;
    for (int i = 0; (i < n) && !ok; ++i)
      for (int j = 0; j < n && !ok; ++j) {
        if (i == j) continue;
        int j1 = 0;
        while (b[j].find(b[i][j1], j1) != std::string::npos) {
          kek[b[i][j1] - 'a']--;
          j1++;
          ok = 1;
        }
        if (ok) {
          b[i] = b[j] + b[i].substr(j1, b[i].size());
          b.erase(b.begin() + j);
        }
      }
    if (!ok) break;
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < 27; ++i)
    if (kek[i] > 1) {
      cout << "NO";
      return 0;
    }
  string z = "";
  for (auto i : b) z += i;
  for (auto i : b)
    if (z.find(i) != std::string::npos) {
      cout << "NO";
      return 0;
    }
  for (auto i : b) cout << i;
  return 0;
}
