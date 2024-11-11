#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(100001);
int dp1[100001], dp2[100001], freq[5 * 100001], distinctIsoCount;
map<long long, int> hshMap;
pair<int, int> ans;
void PreProcess(int n) { hshMap[1ll * INT_MAX] = 0; }
int GetSubtreeNo(long long subtreeHash) {
  auto it = hshMap.find(subtreeHash);
  if (it != hshMap.end())
    return it->second;
  else {
    hshMap.insert(make_pair(subtreeHash, hshMap.size()));
    return hshMap.size() - 1;
  }
}
void DFS1(int i, int p) {
  vector<int> v;
  long long subtreeHash = 0;
  for (auto k : adj[i]) {
    if (k != p) {
      DFS1(k, i);
      v.push_back(dp1[k]);
    }
  }
  if (v.size() == 0) v.push_back(0);
  sort(v.begin(), v.end());
  for (auto x : v) subtreeHash = (subtreeHash * 1000003 + x) % 1000000007;
  dp1[i] = GetSubtreeNo(subtreeHash);
}
void DFS2(int i, int p) {
  vector<pair<int, int> > v;
  vector<long long> subtreeHashes;
  for (auto k : adj[i]) {
    if (k != p) v.push_back(make_pair(dp1[k], k));
  }
  v.push_back(make_pair(dp2[i], p));
  sort(v.begin(), v.end());
  subtreeHashes.resize(v.size());
  long long prefixHash = 0;
  for (int x = 0; x < v.size(); x++) {
    subtreeHashes[x] = prefixHash;
    prefixHash = (prefixHash * 1000003 + v[x].first) % 1000000007;
  }
  long long suffixHash = 0, suffixHashPower = 1;
  for (int x = v.size() - 1; x > -1; x--) {
    subtreeHashes[x] =
        (subtreeHashes[x] * suffixHashPower + suffixHash) % 1000000007;
    suffixHash = (v[x].first * suffixHashPower + suffixHash) % 1000000007;
    suffixHashPower = (1000003 * suffixHashPower) % 1000000007;
    if (v[x].second != p) {
      dp2[v[x].second] = GetSubtreeNo(subtreeHashes[x]);
      DFS2(v[x].second, i);
    }
  }
}
void IncrementSubtreeFreq(int subtreeNo) {
  freq[subtreeNo]++;
  distinctIsoCount += (freq[subtreeNo] == 1);
}
void DecrementSubtreeFreq(int subtreeNo) {
  freq[subtreeNo]--;
  distinctIsoCount -= (freq[subtreeNo] == 0);
}
void DFS(int i, int p) {
  DecrementSubtreeFreq(dp1[i]);
  for (auto k : adj[i]) {
    if (k != p) {
      IncrementSubtreeFreq(dp2[k]);
      DFS(k, i);
      DecrementSubtreeFreq(dp2[k]);
    }
  }
  ans = max(ans, make_pair(distinctIsoCount, i));
  IncrementSubtreeFreq(dp1[i]);
}
int main() {
  int n, root;
  scanf("%d", &n);
  for (int k = 1; k < n; k++) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  for (root = 1; root <= n && adj[root].size() > 1; root++)
    ;
  PreProcess(n);
  DFS1(root, 0);
  DFS2(root, 0);
  for (int i = 1; i <= n; i++) IncrementSubtreeFreq(dp1[i]);
  DFS(root, 0);
  printf("%d\n", ans.second);
  return 0;
}
