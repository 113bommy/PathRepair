#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 998244353;
int mult(long long a, long long b) { return (a * b) % MOD; }
int pot(int n, int k) {
  int ret = 1, pot = n;
  for (; k > 0; k >>= 1, pot = mult(pot, pot))
    ret = mult(ret, (k & 1) ? pot : 1);
  return ret;
}
int divide(int a, int b) { return mult(a, pot(b, MOD - 2)); }
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
struct Node {
  int lo, hi, LL, LR, RL, RR;
  Node(int first, int second, int a, int b, int c, int d) {
    lo = first, hi = second, LL = a, LR = b, RL = c, RR = d;
  }
  void print() {
    cout << lo << ' ' << hi << " | " << LL << ' ' << LR << ' ' << RL << ' '
         << RR << "\n";
  }
};
int n, POT = 1;
int X[maxn], V[maxn], P[maxn];
vector<Node> tree;
int C[maxn][4];
pair<int, int> TP[maxn][4];
Node merge(int first) {
  Node L = tree[first * 2], R = tree[first * 2 + 1];
  Node ret = tree[first];
  ret.lo = L.lo, ret.hi = R.hi;
  ret.LL = mult(mult(L.LL, R.LL), C[L.hi][0]);
  ret.LL = add(ret.LL, mult(mult(L.LL, R.RL), C[L.hi][1]));
  ret.LL = add(ret.LL, mult(mult(L.LR, R.LL), C[L.hi][2]));
  ret.LL = add(ret.LL, mult(mult(L.LR, R.RL), C[L.hi][3]));
  ret.LR = mult(mult(L.LL, R.LR), C[L.hi][0]);
  ret.LR = add(ret.LR, mult(mult(L.LL, R.RR), C[L.hi][1]));
  ret.LR = add(ret.LR, mult(mult(L.LR, R.LR), C[L.hi][2]));
  ret.LR = add(ret.LR, mult(mult(L.LR, R.RR), C[L.hi][3]));
  ret.RL = mult(mult(L.RL, R.LL), C[L.hi][0]);
  ret.RL = add(ret.RL, mult(mult(L.RL, R.RL), C[L.hi][1]));
  ret.RL = add(ret.RL, mult(mult(L.RR, R.LL), C[L.hi][2]));
  ret.RL = add(ret.RL, mult(mult(L.RR, R.RL), C[L.hi][3]));
  ret.RR = mult(mult(L.RL, R.LR), C[L.hi][0]);
  ret.RR = add(ret.RR, mult(mult(L.RL, R.RR), C[L.hi][1]));
  ret.RR = add(ret.RR, mult(mult(L.RR, R.LR), C[L.hi][2]));
  ret.RR = add(ret.RR, mult(mult(L.RR, R.RR), C[L.hi][3]));
  return ret;
}
void update(int first, int second) {
  C[first][second] = 0;
  first += POT;
  first /= 2;
  for (; first > 0; first >>= 1) tree[first] = merge(first);
}
int query() {
  return add(add(tree[1].LL, tree[1].LR), add(tree[1].RL, tree[1].RR));
}
map<double, int> mapa;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d %d", X + i, V + i, P + i);
  while (POT < n) POT <<= 1;
  for (int i = 0; i < POT; i++)
    C[i][0] = 1, C[i][1] = 1, C[i][2] = 1, C[i][3] = 1;
  for (int i = 0; i < POT * 2; i++)
    tree.push_back(Node(i - POT, i - POT, 0, 0, 0, 0));
  for (int i = 0; i < n; i++)
    tree[i + POT] =
        Node(i, i, divide(sub(100, P[i]), 100), 0, 0, divide(P[i], 100));
  for (int i = POT - 1; i >= 1; i--) tree[i] = merge(i);
  vector<pair<double, pair<int, int>>> v;
  for (int i = 0; i < n - 1; i++) {
    double T1 = (double)((double)X[i + 1] - X[i]) / ((double)V[i] - V[i + 1]);
    int t1 = divide(sub(X[i + 1], X[i]), sub(V[i], V[i + 1]));
    int p1 = mult(divide(P[i], 100), divide(P[i + 1], 100));
    double T2 = (double)((double)X[i + 1] - X[i]) / ((double)V[i + 1] - V[i]);
    int t2 = divide(sub(X[i + 1], X[i]), sub(V[i + 1], V[i]));
    int p2 = mult(divide(sub(100, P[i]), 100), divide(sub(100, P[i + 1]), 100));
    double T3 = (double)((double)X[i + 1] - X[i]) / ((double)V[i] + V[i + 1]);
    int t3 = divide(sub(X[i + 1], X[i]), add(V[i], V[i + 1]));
    int p3 = mult(divide(P[i], 100), divide(sub(100, P[i + 1]), 100));
    double T4 = (double)((double)X[i] - X[i + 1]) / ((double)V[i] + V[i + 1]);
    int t4 = divide(sub(X[i], X[i + 1]), add(V[i], V[i + 1]));
    int p4 = mult(divide(sub(100, P[i]), 100), divide(P[i + 1], 100));
    TP[i][3] = {t1, p1};
    TP[i][0] = {t2, p2};
    TP[i][2] = {t3, p3};
    TP[i][1] = {t4, p4};
    if (T1 >= 0 && p1 > 0) v.push_back({T1, {i, 3}});
    if (T2 >= 0 && p2 > 0) v.push_back({T2, {i, 0}});
    if (T3 >= 0 && p3 > 0) v.push_back({T3, {i, 2}});
    if (T4 >= 0 && p4 > 0) v.push_back({T4, {i, 1}});
  }
  if (v.size() == 0) {
    printf("0\n");
    return 0;
  }
  sort((v).begin(), (v).end());
  int exp = 0;
  for (pair<double, pair<int, int>> p : v) {
    int first = query();
    update(p.second.first, p.second.second);
    first = sub(first, query());
    exp = add(exp, mult(first, TP[p.second.first][p.second.second].first));
  }
  printf("%d\n", exp);
  return 0;
}
