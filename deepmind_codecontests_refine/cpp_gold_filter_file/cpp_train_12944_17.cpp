#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const ll MODBASE = 1000000007LL;
const int MAXN = 2010;
const int MAXM = 200010;
const int MAXK = 110;
const int MAXQ = 200010;
int n, K;
ll dp[MAXN * 2][MAXN], tmp[MAXN];
struct TrieNode {
  TrieNode *children[27];
  int depth, cnt;
};
TrieNode *getNode() {
  TrieNode *pNode = new TrieNode;
  pNode->depth = 0;
  pNode->cnt = 0;
  for (int i = (0); i <= (26); i++) pNode->children[i] = nullptr;
  return pNode;
}
void insert(TrieNode *root, string &key) {
  root->cnt++;
  TrieNode *pCrawl = root;
  for (int i = (0); i <= (int((key).size()) - 1); i++) {
    int index = key[i] - 'a';
    if (key[i] == '$') index = 26;
    if (!pCrawl->children[index]) {
      pCrawl->children[index] = getNode();
      pCrawl->children[index]->depth = pCrawl->depth + 1;
    }
    pCrawl = pCrawl->children[index];
    pCrawl->cnt++;
  }
}
int nowId = 0;
int getId() { return nowId++; }
int calc(TrieNode *root) {
  int nodeId = -1;
  int posChild = -1, cntChild = 0;
  for (int i = (0); i <= (26); i++)
    if (root->children[i] != nullptr) {
      cntChild++;
      posChild = i;
    }
  if (posChild == -1) {
    nodeId = getId();
    for (int i = (0); i <= (min(root->cnt, K)); i++)
      dp[nodeId][i] = (ll)(root->depth - 1) * i * (i - 1) / 2;
    return nodeId;
  }
  if (cntChild == 1) return calc(root->children[posChild]);
  nodeId = getId();
  for (int i = (0); i <= (K); i++) dp[nodeId][i] = 0;
  int numOfString = 0;
  for (int i = (0); i <= (26); i++)
    if (root->children[i] != nullptr) {
      int childNodeId = calc(root->children[i]);
      int numStringAtChild = root->children[i]->cnt;
      for (int j = (0); j <= (K); j++) tmp[j] = 0;
      for (int j = (0); j <= (min(K, numOfString)); j++)
        for (int k = (0); k <= (min(K, numStringAtChild)); k++) {
          if (j + k <= K)
            tmp[j + k] =
                max(tmp[j + k], (ll)dp[nodeId][j] + dp[childNodeId][k] +
                                    (ll)j * k * root->depth);
          else
            break;
        }
      for (int j = (0); j <= (K); j++) dp[nodeId][j] = tmp[j];
      numOfString += numStringAtChild;
    }
  return nodeId;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> K;
  TrieNode *root = getNode();
  for (int i = (0); i <= (n - 1); i++) {
    string t;
    cin >> t;
    t = t + "$";
    insert(root, t);
  }
  int nodeId = calc(root);
  cout << dp[nodeId][K];
  return 0;
}
