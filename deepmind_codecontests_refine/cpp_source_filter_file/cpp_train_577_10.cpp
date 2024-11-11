#include <bits/stdc++.h>
using namespace std;
const int MAXN = 130;
void operator+=(vector<int> &v1, vector<int> v2) {
  v1.insert(v1.end(), (v2).begin(), (v2).end());
}
vector<int> operator+(vector<int> v1, vector<int> v2) {
  v1 += v2;
  return v1;
}
int N, Q;
vector<int> cache[MAXN];
int level[MAXN];
void reset() {
  for (int i = 0; i < MAXN; i++) {
    cache[i].clear();
    level[i] = 0;
  }
}
bool cached(int x) { return !cache[x].empty(); }
vector<int> query(int x) {
  vector<int> &res = cache[x];
  if (cached(x)) {
    return res;
  }
  if ((Q++) == 16) {
    throw 129;
  }
  cout << "? " << x << endl;
  int sz;
  cin >> sz;
  res.resize(sz);
  for (int i = 0; i < sz; i++) {
    cin >> res[i];
  }
  if (sz == 2) {
    throw x;
  }
  return res;
}
vector<int> qpath(int x, int p) {
  vector<int> vec;
  while (true) {
    vec.push_back(x);
    vector<int> qx = query(x);
    qx.erase(find((qx).begin(), (qx).end(), p));
    if (qx.empty()) {
      break;
    }
    p = x;
    x = qx[0];
  }
  return vec;
}
vector<int> path2(int x) {
  vector<int> qx = query(x);
  if (qx.size() == 3) {
    if (cached(qx[2])) {
      swap(qx[2], qx[1]);
    }
  }
  vector<int> vec;
  for (int i = 0; i < 2 && i < qx.size(); i++) {
    vector<int> v = qpath(qx[i], x);
    if (i == 0) {
      reverse((v).begin(), (v).end());
      v.push_back(x);
    }
    vec += v;
  }
  assert(vec.size() % 2);
  int mid = vec.size() / 2, levx = N - mid;
  for (int i = 0; i < vec.size(); i++) {
    level[vec[i]] = levx + abs(mid - i);
  }
  return vec;
}
int par[MAXN];
void go() {
  reset();
  cin >> N;
  int cur = 1, pacur = 0;
  while (true) {
    vector<int> pth = path2(cur);
    int imid = pth.size() / 2;
    int vmid = pth[imid];
    vector<int> qmid = query(vmid);
    for (int v : {pth[imid - 1], pth[imid + 1]}) {
      qmid.erase(find((qmid).begin(), (qmid).end(), v));
    }
    assert(level[vmid]);
    pacur = vmid;
    cur = qmid[0];
    if (level[vmid] <= 4) {
      break;
    }
  }
  memset(par, 0, sizeof(par));
  queue<int> que;
  que.push(cur);
  par[cur] = pacur;
  while (!que.empty()) {
    int fro = que.front();
    if (Q == 16) {
      throw fro;
    }
    que.pop();
    for (int y : query(fro)) {
      if (y != par[fro]) {
        que.push(y);
        par[y] = fro;
      }
    }
  }
}
int main() {
  int nt;
  for (cin >> nt; nt--;) {
    try {
      go();
    } catch (int ans) {
      cout << "! " << ans << endl;
    }
  }
}
