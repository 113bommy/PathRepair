#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using rl = double;
const int MAXN = 5 * 100009;
const int modd = 998244353;
int n;
struct Vertex {
  vector<int> to;
  int pm, answ, thisansw;
} v[MAXN];
int ndiv2;
int mult(int a, int b) {
  ll res = a * (ll)b;
  if (res >= modd) res %= modd;
  return res;
}
int add(int a, int b) {
  a += b;
  if (a >= modd) a -= modd;
  return a;
}
int neg(int a) {
  a = -a;
  if (a < 0) a += modd;
  return a;
}
int oneMinus(int a) { return add(1, neg(a)); }
int poww(int val, int pow = modd - 2) {
  int res = 1;
  while (pow) {
    if (pow & 1) res = mult(res, val);
    val = mult(val, val);
    pow /= 2;
  }
  return res;
}
int dfs(int it, int p = 0) {
  v[it].pm = 1;
  v[it].answ = 0;
  v[it].thisansw = 0;
  for (auto to : v[it].to) {
    if (to == p) continue;
    v[it].answ = add(v[it].answ, dfs(to, it));
    v[it].thisansw =
        mult(v[it].thisansw, add(oneMinus(v[to].pm), mult(ndiv2, v[to].pm)));
    v[it].thisansw = add(v[it].thisansw, mult(ndiv2, v[to].pm));
    v[it].pm = mult(v[it].pm, add(oneMinus(v[to].pm), mult(ndiv2, v[to].pm)));
  }
  return add(v[it].answ, v[it].thisansw);
}
int main() {
  ndiv2 = poww(2);
  assert(mult(ndiv2, 2) == 1);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].to.push_back(b);
    v[b].to.push_back(a);
  }
  int answ = dfs(1);
  printf("%d\n", mult(pow(2, n), answ));
}
