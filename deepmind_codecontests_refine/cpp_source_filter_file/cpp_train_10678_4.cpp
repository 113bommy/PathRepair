#include <bits/stdc++.h>
using namespace std;
const int SQ = 500;
int group(int x) { return x / SQ; }
int stackSize[SQ];
pair<int, int> operations[101005];
vector<int> groupStacks[SQ];
void update(int i, pair<int, int> op) {
  operations[i] = op;
  int g = group(i);
  stackSize[g] = 0;
  groupStacks[g].clear();
  for (int e = g * SQ; e < g * SQ + SQ; e++) {
    if (operations[e].first == 0) {
      stackSize[g]--;
      if (groupStacks[g].size() > 0) groupStacks[g].pop_back();
    } else if (operations[e].first == 1) {
      stackSize[g]++;
      groupStacks[g].push_back(operations[e].second);
    }
  }
}
int query(int groupNumber, int accSize) {
  if (groupNumber == -1)
    return -1;
  else {
    int k = accSize + stackSize[groupNumber];
    if ((int)(groupStacks[groupNumber].size()) - accSize > 0)
      return groupStacks[groupNumber]
                        [(int)(groupStacks[groupNumber].size()) - accSize - 1];
    else
      return query(groupNumber - 1, k);
  }
}
int main() {
  for (int e = 0; e < 101005; e++) operations[e] = make_pair(-1, -1);
  int n;
  scanf("%i", &n);
  for (int e = 0; e < n; e++) {
    int a, b;
    scanf("%i%i", &a, &b);
    a--;
    int c = 0;
    if (b == 1) {
      scanf("%i", &c);
    }
    update(a, make_pair(b, c));
    printf("%i\n", query(group(n), 0));
  }
}
