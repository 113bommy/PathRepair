#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 11;
const int MOD2 = 1;
struct Hash {
  Hash(int x) : first(x % MOD1), second(x % MOD2) {}
  Hash() : first(0), second(0) {}
  int first;
  int second;
};
const Hash P = Hash(31);
bool operator<(const Hash& lhs, const Hash& rhs) {
  return lhs.first < rhs.first ||
         (lhs.first == rhs.first && lhs.second < rhs.second);
}
bool operator==(const Hash& lhs, const Hash& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}
Hash& operator*=(Hash& lhs, const Hash& rhs) {
  lhs.first = (1LL * lhs.first * rhs.first) % MOD1;
  lhs.second = (1LL * lhs.second * rhs.second) % MOD2;
  return lhs;
}
Hash operator*(const Hash& lhs, const Hash& rhs) {
  Hash result(lhs);
  result *= rhs;
  return result;
}
Hash& operator+=(Hash& lhs, const Hash& rhs) {
  lhs.first += rhs.first;
  if (lhs.first >= MOD1) {
    lhs.first -= MOD1;
  }
  lhs.second += rhs.second;
  if (lhs.second >= MOD2) {
    lhs.second -= MOD2;
  }
  return lhs;
}
Hash operator+(const Hash& lhs, const Hash& rhs) {
  Hash result(lhs);
  result += rhs;
  return result;
}
const int MAX_N = 3e5 + 100;
Hash powers[MAX_N];
void BuildPowers() {
  powers[0] = Hash(1);
  for (int i = 1; i < MAX_N; ++i) {
    powers[i] = P;
    powers[i] *= powers[i - 1];
  }
}
Hash& operator<<=(Hash& lhs, int rhs) {
  lhs *= powers[rhs];
  return lhs;
}
Hash operator<<(const Hash& lhs, int rhs) {
  Hash result(lhs);
  result <<= rhs;
  return result;
}
int n;
int c[MAX_N];
long long ans[MAX_N];
string s;
vector<vector<int>> g;
Hash hashes[MAX_N];
set<Hash> diffHashes[MAX_N];
void Merge(set<Hash>& lhs, set<Hash>& rhs) {
  if (lhs.size() < rhs.size()) {
    swap(lhs, rhs);
  }
  for (const Hash& h : rhs) {
    lhs.insert(h);
  }
}
void Dfs(int v, int pr, int d) {
  hashes[v] = Hash(s[v] - 'a' + 1);
  if (d != 0) {
    hashes[v] <<= d;
    hashes[v] += hashes[pr];
  }
  for (int i : g[v]) {
    if (i == pr) {
      continue;
    }
    Dfs(i, v, d + 1);
  }
  diffHashes[v].insert(hashes[v]);
  for (int i : g[v]) {
    if (i == pr) {
      continue;
    }
    Merge(diffHashes[v], diffHashes[i]);
  }
  ans[v] = 0ll + diffHashes[v].size() + c[v];
}
void ShowAns() {
  long long ansValue = ans[0];
  int ansCount = 1;
  for (int i = 1; i < n; ++i) {
    if (ans[i] == ansValue) {
      ++ansCount;
    } else if (ans[i] > ansValue) {
      ansValue = ans[i];
      ansCount = 1;
    }
  }
  cout << ansValue << endl;
  cout << ansCount << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BuildPowers();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  cin >> s;
  g.resize(n);
  for (int i = 0; i + 1 < n; ++i) {
    int v1, v2;
    cin >> v1 >> v2;
    --v1;
    --v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  Dfs(0, -1, 0);
  ShowAns();
  return 0;
}
