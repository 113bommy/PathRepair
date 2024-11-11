#include <bits/stdc++.h>
using namespace std;
static const int MAX = 1048576;
int H, M, N;
void Read() { scanf("%d%d%d", &H, &M, &N); }
int TreeSize, TreeCapacity, TreeCount;
int FindHash(int tree[], int hash) {
  hash += TreeCapacity;
  if (tree[hash] != -1) return tree[hash];
  while (hash != 1) {
    if ((hash & 1) == 0) {
      if (tree[hash ^ 1] != -1) return tree[hash ^ 1];
    }
    hash >>= 1;
  }
  return tree[1];
}
void UpdateTree(int tree[], int hash, int value) {
  hash += TreeCapacity;
  tree[hash] = value;
  while (hash != 1) {
    if (tree[hash] == -1 && tree[hash ^ 1] == -1)
      tree[hash >> 1] = -1;
    else if (tree[hash] == -1)
      tree[hash >> 1] = tree[hash ^ 1];
    else if (tree[hash ^ 1] == -1)
      tree[hash >> 1] = tree[hash];
    else
      tree[hash >> 1] = min(tree[hash], tree[hash ^ 1]);
    hash >>= 1;
  }
}
void AddTree(int tree[], int hash) { UpdateTree(tree, hash, -1); }
void DropTree(int tree[], int hash) { UpdateTree(tree, hash, hash); }
void InitTree(int tree[]) {
  int h;
  for (h = 0; h < TreeSize; ++h) tree[h + TreeCapacity] = h;
  for (h = TreeCapacity - 1; h >= 1; --h) tree[h] = tree[h << 1];
}
map<int, int *> IdTree;
map<int, int> IdTreeHash;
int AddTree(int tree[], int hash, int id) {
  int result;
  int new_hash = FindHash(tree, hash);
  AddTree(tree, new_hash);
  if (new_hash >= hash)
    result = new_hash - hash;
  else
    result = new_hash + TreeSize - hash;
  IdTree.insert(make_pair(id, tree));
  IdTreeHash.insert(make_pair(id, new_hash));
  return result;
}
void DropTree(int tree[], int hash, int id) {
  DropTree(tree, hash);
  IdTree.erase(id);
  IdTreeHash.erase(id);
}
int Tree[MAX];
int TreeId[MAX];
int TreeHash[MAX];
int AddTree(int hash, int id) {
  int *tree = Tree + TreeCapacity * 2 * TreeId[hash];
  return AddTree(tree, TreeHash[hash], id);
}
void DropTree(int id) { DropTree(IdTree[id], IdTreeHash[id], id); }
void InitTree() {
  int i;
  memset(Tree, -1, sizeof(Tree));
  for (i = 0; i < TreeCount; ++i) InitTree(Tree + TreeCapacity * 2 * i);
}
int NOD(int x, int y) {
  while (true) {
    if (x == 0) return y;
    y %= x;
    if (y == 0) return x;
    x %= y;
  }
}
long long Result;
void Work() {
  int i, j, k, n, m;
  TreeCount = NOD(H, M);
  TreeSize = H / TreeCount;
  for (TreeCapacity = 1; TreeCapacity < TreeSize; TreeCapacity <<= 1)
    ;
  InitTree();
  memset(TreeId, -1, sizeof(TreeId));
  memset(TreeHash, -1, sizeof(TreeHash));
  k = 0;
  for (i = 0; i < H; ++i) {
    if (TreeId[i] != -1) continue;
    for (j = i, m = 0; TreeId[j] == -1; j = (j + M) % H) {
      TreeId[j] = k;
      TreeHash[j] = m++;
    }
    ++k;
  }
  Result = 0;
  for (n = 0; n < N; ++n) {
    char op;
    int id;
    scanf(" %c%d", &op, &id);
    if (op == '+') {
      int hash;
      scanf("%d", &hash);
      Result += AddTree(hash, id);
    } else {
      DropTree(id);
    }
  }
}
void Write() { printf("%I64d\n", Result); }
int main() {
  Read();
  Work();
  Write();
  return 0;
}
