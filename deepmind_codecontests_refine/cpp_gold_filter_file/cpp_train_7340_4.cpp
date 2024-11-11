#include <bits/stdc++.h>
using namespace std;
int n, par[100042], parq[100042], k;
vector<int> to[100042], toq[100042], input[100042];
vector<int> dfsPath;
int onInd[100042], lpar[100042][20], nd[100042];
void read() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int ki;
    cin >> ki;
    for (int j = 0; j < ki; j++) {
      int a;
      cin >> a;
      input[i].push_back(a);
    }
  }
}
void setTr(int x) {
  onInd[x] = dfsPath.size();
  dfsPath.push_back(x);
  for (int i = 0; i < to[x].size(); i++) {
    if (to[x][i] == par[x]) {
      swap(to[x][i], to[x][to[x].size() - 1]);
      to[x].pop_back();
      i--;
    } else {
      par[to[x][i]] = x;
      setTr(to[x][i]);
    }
  }
}
void setPar(int x, int d) {
  nd[x] = d;
  lpar[x][0] = par[x];
  for (int st = 1; (1 << st) <= d; st++) {
    lpar[x][st] = lpar[lpar[x][st - 1]][st - 1];
  }
  for (int i = 0; i < to[x].size(); i++) {
    setPar(to[x][i], d + 1);
  }
}
int lca(int a, int b) {
  int minD = min(nd[a], nd[b]);
  if (nd[a] > nd[b]) {
    swap(a, b);
  }
  for (int st = 20; st >= 0; st--) {
    if (nd[b] - (1 << st) >= minD) {
      b = lpar[b][st];
    }
  }
  for (int st = 20; a != b; st--) {
    if (st < 0) {
      st = 0;
    }
    if (nd[b] - (1 << st) < 0) {
      continue;
    }
    if (lpar[a][st] == lpar[b][st] && st) {
      continue;
    }
    a = lpar[a][st];
    b = lpar[b][st];
  }
  return a;
}
vector<int> dfsInds;
vector<int> inodes;
bool isImp[1000042], used[1000042];
int dp[1000042][2], root = -1;
void solveT(int x) {
  dp[x][0] = 0;
  dp[x][1] = 0;
  int sum0 = 0, sumMin = 0;
  for (int i = 0; i < toq[x].size(); i++) {
    solveT(toq[x][i]);
    sum0 += dp[toq[x][i]][0];
    sumMin += min(dp[toq[x][i]][0], dp[toq[x][i]][1]);
  }
  if (isImp[x]) {
    dp[x][0] = 1 + sum0;
    dp[x][1] = sum0;
  } else {
    int min10 = 1 << 29;
    for (int i = 0; i < toq[x].size(); i++) {
      min10 = min(min10, dp[toq[x][i]][1] - dp[toq[x][i]][0]);
    }
    dp[x][1] = sum0 + min10;
    dp[x][0] = min(sum0, sumMin + 1);
  }
}
stack<int> s;
void solve(int qind) {
  for (int i = 0; i < inodes.size(); i++) {
    isImp[inodes[i]] = 0;
    toq[inodes[i]].clear();
    parq[inodes[i]] = 0;
    used[inodes[i]] = 0;
    dp[inodes[i]][0] = 0;
    dp[inodes[i]][1] = 0;
  }
  while (!s.empty()) {
    s.pop();
  }
  inodes.clear();
  dfsInds.clear();
  for (int i = 0; i < input[qind].size(); i++) {
    dfsInds.push_back(onInd[input[qind][i]]);
    isImp[dfsPath[dfsInds[i]]] = 1;
  }
  sort(dfsInds.begin(), dfsInds.end());
  for (int i = 0; i < dfsInds.size() - 1; i++) {
    int a = dfsPath[dfsInds[i]], b = dfsPath[dfsInds[i + 1]];
    inodes.push_back(a);
    int clca = lca(a, b);
    if (parq[a] == 0) {
      parq[a] = clca;
      s.push(clca);
    } else {
      int last = s.top();
      while (!s.empty() && nd[s.top()] >= nd[clca]) {
        last = s.top();
        s.pop();
      }
      if (s.empty()) {
        parq[last] = clca;
      } else {
        if (lca(last, clca) == clca) {
          parq[last] = clca;
        }
        parq[clca] = s.top();
      }
      s.push(clca);
    }
    parq[b] = clca;
    s.push(b);
    inodes.push_back(clca);
  }
  inodes.push_back(dfsPath[dfsInds.back()]);
  root = -1;
  for (int i = 0; i < inodes.size(); i++) {
    if (used[inodes[i]]) {
      continue;
    }
    used[inodes[i]] = 1;
    if (parq[inodes[i]] == 0 || inodes[i] == parq[inodes[i]]) {
      if (root != -1 && root != inodes[i]) {
        cout << "hula hula\n";
      }
      root = inodes[i];
    } else {
      toq[parq[inodes[i]]].push_back(inodes[i]);
      if (parq[inodes[i]] == par[inodes[i]] && isImp[parq[inodes[i]]] &&
          isImp[inodes[i]]) {
        cout << "-1\n";
        return;
      }
    }
  }
  solveT(root);
  if (n == 100 && qind == 2 && min(dp[root][1], dp[root][0]) != 1 && 0) {
    cout << root << ":\n";
    for (int i = 0; i < inodes.size(); i++) {
      cout << parq[inodes[i]] << " " << inodes[i] << " (" << nd[inodes[i]]
           << ") "
           << "\n";
    }
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < input[qind].size(); i++) {
      cout << input[qind][i] << " ";
    }
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < dfsInds.size() - 1; i++) {
      int a = dfsPath[dfsInds[i]], b = dfsPath[dfsInds[i + 1]];
      cout << a << " " << b << " -> " << lca(a, b) << "\n";
    }
  }
  cout << min(dp[root][1], dp[root][0]) << "\n";
}
int main() {
  read();
  setTr(1);
  setPar(1, 0);
  for (int i = 0; i < k; i++) {
    solve(i);
  }
  return 0;
}
