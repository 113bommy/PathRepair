#include <bits/stdc++.h>
const int INF = 1000 * 1000 * 1000;
using namespace std;
int n;
const int uh = 2001 * 715;
const int qwer = 512;
int a[2000], b[2000];
int q[uh * 10];
int dist[uh * 10];
int updation[715][10];
int deletion[715][10];
int qh, qt;
int isFree[715];
int curD;
int getHash(vector<int> v) {
  return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}
vector<int> hashes;
vector<vector<int> > states;
vector<int> sequence;
void rec() {
  if (sequence.size() == 4) {
    states.push_back(sequence);
    hashes.push_back(getHash(sequence));
    return;
  }
  int x = sequence.size() ? sequence.back() : 0;
  for (int i = x; i <= 9; i++) {
    sequence.push_back(i);
    rec();
    sequence.pop_back();
  }
}
bool have(int state, int floor, bool output = false) {
  for (int i = 0; i < states[state].size(); i++) {
    if (output) cout << states[state][i] << " ";
    if (states[state][i] == floor) {
      return true;
    }
  }
  return false;
}
void update(int v) {
  if (dist[v] == -1) {
    dist[v] = curD + 1;
    q[qt++] = v;
  }
}
int upd(int u, int v) {
  vector<int> V = states[u];
  for (int i = 0; i < V.size(); i++) {
    if (V[i] == 0) {
      V[i] = v;
      break;
    }
  }
  sort(V.begin(), V.end());
  return lower_bound(hashes.begin(), hashes.end(), getHash(V)) - hashes.begin();
}
int makeNode(int floor, int idx, int state) {
  return state + idx * 715 + floor * 715 * 2000;
}
int getFloor(int x) { return x / (715 * 2000); }
int getIdx(int x) {
  x %= 715 * 2000;
  return x / 715;
}
int getState(int x) { return x % 715; }
int del(int state, int floor) {
  vector<int> v = states[state];
  vector<int> newV;
  bool wasDel = false;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == floor && !wasDel) {
      wasDel = true;
    } else
      newV.push_back(v[i]);
  }
  newV.push_back(0);
  sort(newV.begin(), newV.end());
  return lower_bound(hashes.begin(), hashes.end(), getHash(newV)) -
         hashes.begin();
}
int f(int floor, int state) {
  if (state == 0) return 0;
  vector<int> v = states[state];
  int leftest = INF, rightest = -INF;
  int cnt = 0;
  for (int i = 0; i < v.size(); i++)
    if (v[i]) {
      cnt++;
      leftest = min(leftest, v[i]);
      rightest = max(rightest, v[i]);
    }
  if (rightest <= floor) {
    return cnt + floor - leftest;
  }
  if (leftest >= floor) {
    return cnt + rightest - floor;
  }
  return cnt + rightest - leftest + min(rightest - floor, floor - leftest);
}
int main() {
  ios_base::sync_with_stdio(0);
  rec();
  for (int i = 0; i < states.size(); i++) {
    for (int j = 0; j < states[i].size(); j++) {
      isFree[i] |= states[i][j] == 0;
    }
  }
  for (int i = 0; i < states.size(); i++) {
    if (isFree[i])
      for (int j = 1; j <= 9; j++) updation[i][j] = upd(i, j);
    for (int j = 1; j <= 9; j++)
      if (have(i, j)) deletion[i][j] = del(i, j);
  }
  memset(dist, -1, sizeof dist);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  dist[makeNode(1, 0, 0)] = 0;
  q[qt++] = makeNode(1, 0, 0);
  int ans = INF;
  while (qh != qt) {
    int u = q[qh++];
    int floor = getFloor(u);
    int idx = getIdx(u);
    int state = getState(u);
    curD = dist[u];
    if (idx == n && state == 0) {
      ans = min(ans, curD + f(floor, state));
      continue;
    }
    if (floor != 9) {
      update(makeNode(floor + 1, idx, state));
    }
    if (floor != 1) {
      update(makeNode(floor - 1, idx, state));
    }
    if (idx < n && a[idx] == floor && isFree[state]) {
      update(makeNode(floor, idx + 1, updation[state][b[idx]]));
    }
    if (have(state, floor)) {
      update(makeNode(floor, idx, deletion[state][floor]));
    }
  }
  cout << ans;
  return 0;
}
