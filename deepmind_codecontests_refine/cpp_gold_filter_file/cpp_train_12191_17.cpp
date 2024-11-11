#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)9437184 * 2 * 2 * 2;
const int OO = 0x3f3f3f3f;
struct Primes {
  int maxn;
  vector<int> lp;
  vector<int> primes;
  Primes(int maxn) : maxn(maxn), lp(maxn + 1, -1) {
    for (int i = 2; i <= maxn; i == 2 ? i++ : i += 2) {
      if (lp[i] == -1) {
        lp[i] = i;
        for (long long j = i + i; j <= maxn; j += i) {
          if (lp[j] == -1) {
            lp[j] = i;
          }
        }
      }
    }
    for (int(i) = (2); (i) < (maxn + 1); (i)++) {
      if (lp[i] == i) {
        primes.push_back(i);
      }
    }
  }
} primes(1e6);
int SafePow(int a, int b) {
  int res = 1;
  for (int(i) = (0); (i) < (b); (i)++) {
    if (res * a > MAXN) return -1;
    res *= a;
  }
  return res;
}
int SafeMul(int a, int b) {
  if (b == -1) return -1;
  if (a == -1) return -1;
  if (1ll * a * b > MAXN) return -1;
  return a * b;
}
int n;
vector<int> curVec;
vector<vector<int> > allVecs;
void genVecs(int val, int total, int num, int prim) {
  if (num > MAXN) {
    return;
  }
  if (total < 0) {
    return;
  }
  if (!curVec.empty()) {
    allVecs.push_back(curVec);
  }
  int p = primes.primes[prim];
  int now = num;
  for (int(pow) = (1); (pow) < (val + 1); (pow)++) {
    int nxtNum = SafeMul(now, p);
    if (nxtNum == -1) break;
    curVec.push_back(pow);
    genVecs(pow, total - pow, nxtNum, prim + 1);
    curVec.pop_back();
    now = SafeMul(now, p);
    if (now == -1) break;
  }
}
vector<int> scores;
int FindVec(const vector<int>& v) {
  int res = lower_bound(allVecs.begin(), allVecs.end(), v) - allVecs.begin();
  if (res == (int((allVecs).size()))) {
    return (int((allVecs).size()));
  }
  if (allVecs[res] != v) {
    return (int((allVecs).size()));
  }
  return res;
}
void canonize(vector<int>& v) {
  sort(v.begin(), v.end());
  int newSize = remove(v.begin(), v.end(), 0) - v.begin();
  v.resize(newSize);
}
int Score(const vector<int>& v) {
  int score = 1;
  for (auto k : v) {
    score *= k + 1;
  }
  return score;
}
vector<int> Canon(int n) {
  vector<int> res;
  for (; n != 1;) {
    int k = 0;
    int l = primes.lp[n];
    for (; primes.lp[n] == l; n /= l) {
      k++;
    }
    res.push_back(k);
  }
  canonize(res);
  return res;
}
const int MAX_DWANT = (1 << 9);
const int NVERTS = 742;
bool ready[NVERTS][11][MAX_DWANT + 1];
int value[NVERTS][11][MAX_DWANT + 1];
vector<int> g[NVERTS];
pair<int, int> Where[NVERTS][11][MAX_DWANT + 1];
int DP(int v, int left, int dWant) {
  if (ready[v][left][dWant]) {
    return value[v][left][dWant];
  }
  if (scores[v] == dWant) {
    return 0;
  }
  if (left == 0) {
    return OO;
  }
  int res = OO;
  for (auto u : g[v]) {
    res = min(res, DP(u, left - 1, dWant) + 1);
    Where[v][left][dWant] = make_pair(u, left - 1);
  }
  ready[v][left][dWant] = true;
  value[v][left][dWant] = res;
  return res;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  genVecs(22, 22, 1, 0);
  allVecs.push_back(vector<int>());
  for (auto& v : allVecs) {
    sort(v.begin(), v.end());
  }
  sort(allVecs.begin(), allVecs.end());
  allVecs.resize(unique(allVecs.begin(), allVecs.end()) - allVecs.begin());
  for (int(i) = (0); (i) < ((int((allVecs).size()))); (i)++) {
    scores.push_back(Score(allVecs[i]));
  }
  n = (int((allVecs).size()));
  for (int(v) = (0); (v) < (n); (v)++) {
    vector<int> copy;
    int id;
    if (v == 41) {
      printf("");
    }
    for (int(j) = (0); (j) < ((int((allVecs[v]).size()))); (j)++) {
      copy = allVecs[v];
      copy[j] -= 1;
      canonize(copy);
      id = FindVec(copy);
      if (id != n) {
        g[v].push_back(id);
        g[id].push_back(v);
      }
      copy = allVecs[v];
      copy[j] += 1;
      canonize(copy);
      id = FindVec(copy);
      if (id != n) {
        g[v].push_back(id);
        g[id].push_back(v);
      }
    }
    copy = allVecs[v];
    copy.push_back(1);
    canonize(copy);
    id = FindVec(copy);
    if (id != n) {
      g[v].push_back(id);
      g[id].push_back(v);
    }
  }
  int t;
  cin >> t;
  bool was = false;
  for (int(q) = (0); (q) < (t); (q)++) {
    int a, b;
    cin >> a >> b;
    if (a == 144444000000 && b == 132408 && q == 0) {
      was = true;
    }
    vector<int> A = Canon(a);
    vector<int> B = Canon(b);
    int ai = FindVec(A);
    int bj = FindVec(B);
    int ans = OO;
    for (int(dWant) = (1); (dWant) < (MAX_DWANT + 1); (dWant)++) {
      int left = DP(ai, 10, dWant);
      int right = DP(bj, 10, dWant);
      if (left + right < ans) {
        ans = left + right;
      }
    }
    if (!was) {
      cout << ans << endl;
    }
    if (was && q == 80) {
      cout << a << " " << b;
      return 0;
    }
  }
  return 0;
}
