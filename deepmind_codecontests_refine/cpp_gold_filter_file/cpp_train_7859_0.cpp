#include <bits/stdc++.h>
using namespace std;
const int NMAX = 15005, QMAX = 35005, KMAX = 1005;
const int P = 1e7 + 19, Q = 1e9 + 7;
int value[NMAX], weight[NMAX];
int opElem[QMAX], opType[QMAX];
int qpos[QMAX], answer[QMAX];
int64_t rdp[KMAX], adp[KMAX];
void insert(vector<int>& a, const multiset<int>& b) {
  a.insert(a.end(), b.begin(), b.end());
}
void solve(int k, int left, int right, const multiset<int>& add) {
  int64_t* sdp = new int64_t[NMAX];
  memcpy(sdp, rdp, sizeof rdp);
  for (int p : add) {
    memcpy(adp, rdp, sizeof adp);
    for (int i = 0; i < weight[p]; ++i) rdp[i] = adp[i];
    for (int i = weight[p]; i <= k; ++i)
      rdp[i] = max(adp[i], adp[i - weight[p]] + value[p]);
  }
  if (left == right) {
    int ans = 0;
    for (int i = k; i > 0; --i) {
      ans = ((int64_t)ans * P + rdp[i]) % Q;
    }
    answer[left] = ans;
  } else {
    int mid = (left + right) / 2;
    {
      multiset<int> nadd;
      for (int i = qpos[mid]; i < qpos[right]; ++i) {
        if (opType[i] == 1) {
          nadd.insert(opElem[i]);
        }
      }
      for (int i = qpos[left]; i < qpos[right]; ++i) {
        if (opType[i] == 0) {
          auto it = nadd.find(opElem[i]);
          if (it != nadd.end()) nadd.erase(it);
        }
      }
      solve(k, left, mid, nadd);
    }
    {
      multiset<int> nadd;
      for (int i = qpos[left]; i < qpos[mid + 1]; ++i) {
        if (opType[i] == 0) {
          nadd.insert(opElem[i]);
        } else {
          auto it = nadd.find(opElem[i]);
          if (it != nadd.end()) nadd.erase(it);
        }
      }
      for (int i = qpos[mid + 1]; i < qpos[right]; ++i) {
        if (opType[i] == 1) {
          auto it = nadd.find(opElem[i]);
          if (it != nadd.end()) nadd.erase(it);
        }
      }
      solve(k, mid + 1, right, nadd);
    }
  }
  memcpy(rdp, sdp, sizeof rdp);
  delete[] sdp;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int curr_op = 0;
  for (int i = 0; i < n; ++i) {
    cin >> value[i] >> weight[i];
    opElem[curr_op] = i;
    opType[curr_op] = 0;
    curr_op++;
  }
  int q;
  cin >> q;
  int cntq = 0;
  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;
    switch (type) {
      case 1:
        cin >> value[n] >> weight[n];
        opElem[curr_op] = n++;
        opType[curr_op] = 0;
        curr_op++;
        break;
      case 2:
        cin >> opElem[curr_op];
        opElem[curr_op]--;
        opType[curr_op] = 1;
        curr_op++;
        break;
      case 3:
        qpos[cntq++] = curr_op;
        break;
      default:
        throw 13;
    }
  }
  multiset<int> add;
  for (int i = 0; i < qpos[0]; ++i) {
    if (opType[i] == 0) {
      add.insert(opElem[i]);
    } else {
      add.erase(add.find(opElem[i]));
    }
  }
  for (int i = qpos[0]; i < qpos[cntq - 1]; ++i) {
    if (opType[i] == 1) {
      auto it = add.find(opElem[i]);
      if (it != add.end()) add.erase(it);
    }
  }
  solve(k, 0, cntq - 1, add);
  for (int i = 0; i < cntq; ++i) cout << answer[i] << '\n';
}
