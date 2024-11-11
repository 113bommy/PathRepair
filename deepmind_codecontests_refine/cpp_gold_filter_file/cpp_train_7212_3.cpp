#include <bits/stdc++.h>
using namespace std;
int read(int &x) { return scanf("%d", &x); }
int read(int &x, int &y) { return scanf("%d%d", &x, &y); }
int read(int &x, int &y, int &z) { return scanf("%d%d%d", &x, &y, &z); }
int read(long long &x) { return scanf("%lld", &x); }
int read(long long &x, long long &y) { return scanf("%lld%lld", &x, &y); }
int read(double &x) { return scanf("%lf", &x); }
char buff[2000010];
int read(string &s) {
  int r = scanf("%s", buff);
  s = buff;
  return r;
}
using namespace std;
struct List {
  vector<long long> prefixSum;
  int sz;
  vector<int> vals;
  List(vector<int> V = {}, int K = 0) : vals(V) {
    vals.resize(min((int)vals.size(), K));
    sz = V.size();
    prefixSum.push_back(0);
    for (int i = 0; i < sz; ++i)
      prefixSum.push_back(prefixSum.back() + vals[i]);
  }
};
vector<List> V;
long long mem[3010][3010];
long long dp1(int id, int k) {
  if (id < 0) return 0;
  if (mem[id][k] != -1) return mem[id][k];
  long long w = 0;
  if (V[id].sz <= k)
    w = max(w, dp1(id - 1, k - V[id].sz) + V[id].prefixSum.back());
  w = max(w, dp1(id - 1, k));
  return mem[id][k] = w;
}
long long mem2[3010][3010];
long long dp2(int id, int k) {
  if (id >= V.size()) return 0;
  if (mem2[id][k] != -1) return mem2[id][k];
  long long w = 0;
  if (V[id].sz <= k)
    w = max(w, dp2(id + 1, k - V[id].sz) + V[id].prefixSum.back());
  w = max(w, dp2(id + 1, k));
  return mem2[id][k] = w;
}
struct Fenwick {
  vector<long long> V;
  int hb;
  Fenwick(int N) : V(N + 10) {
    hb = 1;
    while (hb * 2 < V.size()) hb <<= 1;
  }
  void add(int x, long long v) {
    for (int i = x + 1; i < V.size(); i += (i & -i)) {
      V[i] += v;
    }
  }
  long long get(int x) {
    long long r = 0;
    for (int i = x + 1; i > 0; i -= (i & -i)) {
      r += V[i];
    }
    return r;
  }
};
int main() {
  srand(10);
  int N, K;
  read(N, K);
  V = vector<List>(N);
  for (auto &l : V) {
    int sz;
    read(sz);
    vector<int> V(sz);
    for (int &n : V) {
      read(n);
    }
    l = List(V, K);
  }
  sort(V.begin(), V.end(), [](List &a, List &b) { return a.sz < b.sz; });
  memset(mem, -1, sizeof(mem));
  memset(mem2, -1, sizeof(mem2));
  long long best = dp1(N - 1, K);
  for (int k = 1; k <= K; ++k) {
    vector<int> I;
    int last = -1;
    for (int i = 0; i < N; ++i) {
      if (V[i].sz >= k)
        I.push_back(i);
      else
        last = i;
    }
    sort(I.begin(), I.end(), [&](int a, int b) {
      if (V[a].prefixSum[k] != V[b].prefixSum[k])
        return V[a].prefixSum[k] > V[b].prefixSum[k];
      return V[a].prefixSum.back() > V[b].prefixSum.back();
    });
    long long c = 0;
    Fenwick FN(N);
    for (int i : I) {
      int remK = K - k;
      if (remK - c >= 0) {
        int szSmall = FN.get(i);
        int szLarge = c - szSmall;
        for (int szS = szSmall; szS <= remK - szLarge; ++szS) {
          best = max(best, dp1(i - 1, szS) + dp2(i + 1, remK - szS) +
                               V[i].prefixSum[k]);
        }
      }
      FN.add(i, V[i].sz);
      c += V[i].sz;
    }
  }
  cout << best << endl;
}
