#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[100002];
const int h_num = 9;
long long int B[h_num] = {1011235817, 1011235817, 1011235817,
                          987654347,  1011235817, 1021328611,
                          987654347,  1011235817, 1000000007};
struct HASH {
  vector<long long int> val;
  bool emp;
  HASH(int v_ = 0) {
    val.assign(h_num, 0);
    emp = false;
    for (int i = 0; i < h_num; i++) {
      val[i] = v_;
    }
  }
  vector<long long int> get() { return val; }
};
HASH R[100002];
HASH operator*(const HASH &a, const HASH &b) {
  if (a.emp) {
    return b;
  }
  if (b.emp) {
    return a;
  }
  HASH r;
  for (int i = 0; i < h_num; i++) {
    r.val[i] = a.val[i] * b.val[i];
    if (r.val[i] >= B[i]) r.val[i] %= B[i];
  }
  return r;
}
HASH operator+(const HASH &a, HASH &b) {
  if (a.emp) {
    return a;
  }
  if (b.emp) {
    return b;
  }
  HASH r;
  for (int i = 0; i < h_num; i++) {
    r.val[i] = a.val[i] + b.val[i];
    if (r.val[i] >= B[i]) {
      r.val[i] %= B[i];
    }
  }
  return r;
}
HASH h[100002];
map<vector<long long int>, int> tmp;
int dep[100002];
inline void dfs(int b, int pr = -1) {
  vector<HASH> vv;
  for (int i = 0; i < v[b].size(); i++) {
    if (pr != v[b][i]) {
      dfs(v[b][i], b);
      dep[b] = max(dep[b], dep[v[b][i]] + 1);
    }
  }
  for (int i = 0; i < v[b].size(); i++) {
    if (pr != v[b][i]) {
      vv.push_back(h[v[b][i]] + R[dep[b]]);
    }
  }
  if (vv.size() == 0) {
    h[b] = HASH(1);
    return;
  }
  HASH sum = vv[0];
  for (int i = 1; i < vv.size(); i++) {
    sum = sum * vv[i];
  }
  h[b] = sum;
  return;
}
int maxt;
int idd;
inline void dfs2(int b, int pr, map<vector<long long int>, int> &mp, HASH par2,
                 int par_dep) {
  par_dep++;
  mp[h[b].get()]--;
  if (mp[h[b].get()] == 0) {
    mp.erase(h[b].get());
  }
  vector<HASH> vv[2];
  vector<HASH> im1[2];
  vector<HASH> im2[2];
  vector<int> H;
  H.push_back(par_dep);
  for (int i = 0; i < v[b].size(); i++) {
    if (v[b][i] != pr) {
      H.push_back(dep[v[b][i]] + 1);
    }
  }
  sort(H.begin(), H.end(), greater<int>());
  if (H.size() == 1) {
    H.push_back(H.back());
  }
  for (int i = 0; i < v[b].size(); i++) {
    if (v[b][i] != pr) {
      for (int j = 0; j < 2; j++) {
        vv[j].push_back(h[v[b][i]] + R[H[j]]);
      }
    }
  }
  for (int j = 0; j < 2; j++) {
    im1[j] = im2[j] = vv[j];
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 1; i < im1[j].size(); i++) {
      im1[j][i] = im1[j][i] * im1[j][i - 1];
    }
    for (int i = (int)(im2[j].size()) - 2; i >= 0; i--) {
      im2[j][i] = im2[j][i] * im2[j][i + 1];
    }
  }
  HASH par[2];
  par[0] = par2 + R[H[0]];
  par[1] = par2 + R[H[1]];
  HASH cur[2];
  cur[0] = par[0];
  cur[1] = par[1];
  for (int j = 0; j < 2; j++) {
    if (im1[j].size()) {
      cur[j] = cur[j] * im1[j].back();
    }
  }
  mp[cur[0].get()]++;
  if (maxt < mp.size()) {
    maxt = mp.size();
    idd = b;
  }
  if (maxt == mp.size()) {
    idd = min(idd, b);
  }
  mp[cur[0].get()]--;
  if (mp[cur[0].get()] == 0) {
    mp.erase(cur[0].get());
  }
  int id = -1;
  for (int i = 0; i < v[b].size(); i++) {
    if (v[b][i] == pr) continue;
    id++;
    HASH go;
    go.emp = true;
    int flag = 0;
    if (H[0] == dep[v[b][i]] + 1) {
      flag++;
    }
    if (id) {
      go = go * im1[flag][id - 1];
    }
    if (id + 1 < im2[flag].size()) {
      go = go * im2[flag][id + 1];
    }
    go = go * par[flag];
    if (go.emp == true) {
      go = HASH(1);
    }
    mp[go.get()]++;
    dfs2(v[b][i], b, mp, go, H[flag]);
    mp[go.get()]--;
    if (mp[go.get()] == 0LL) {
      mp.erase(go.get());
    }
  }
  mp[h[b].get()]++;
}
bool use[5000000];
vector<int> pr;
int main() {
  for (int i = 2; i < 5000000; i++) {
    if (use[i] == false) {
      for (int j = i * 2; j < 5000000; j += i) {
        use[j] = true;
      }
      pr.push_back(i);
    }
  }
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < 100002; i++) {
    for (int j = 0; j < h_num; j++) {
      R[i].val[j] = pr[rand() % pr.size()];
    }
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int root = 0;
  dfs(root);
  for (int i = 0; i < n; i++) {
    tmp[h[i].get()]++;
  }
  HASH f;
  f.emp = true;
  dfs2(root, -1, tmp, f, -1);
  cout << idd + 1 << endl;
  return 0;
}
