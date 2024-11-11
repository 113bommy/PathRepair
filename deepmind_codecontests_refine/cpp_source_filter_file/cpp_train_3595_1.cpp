#include <bits/stdc++.h>
using namespace std;
const int N = 10010, BASE = 256, MOD = 1000000007;
string str;
vector<string> vet;
vector<unordered_map<int, int>> hashes(N);
int dp[N];
void back(int pos) {
  if (pos == -1) return;
  back(pos - vet[dp[pos]].size());
  printf("%s ", vet[dp[pos]].c_str());
}
int main() {
  int n;
  cin >> n >> str;
  int m;
  cin >> m;
  vet.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> vet[i];
    string &aux = vet[i];
    int h = 0, x = (int)aux.size();
    for (int i = 0; i < x; i++) h = (1LL * BASE * h + tolower(aux[i])) % MOD;
    hashes[x][h] = i;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int h = 0;
    for (int j = i, x = 1; j >= 0; j--, x++) {
      h = (1LL * BASE * h + str[j]) % MOD;
      if (hashes[x].find(h) != hashes[x].end() and (!j or dp[j - 1] != -1)) {
        dp[i] = hashes[x][h];
        break;
      }
    }
  }
  back(n - 1);
  return 0;
}
