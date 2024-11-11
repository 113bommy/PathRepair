#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
int n, m;
int ar[5];
int tree[2];
vector<map<int, pair<int, int> > > t(2);
int func(int l, int r) {
  int ans = (int)1e9;
  map<int, int> mapp;
  map<int, int>::iterator it;
  for (int i = l; i <= r; i++) {
    it = mapp.find(ar[i]);
    if (it == mapp.end()) {
      mapp[ar[i]] = i;
    } else {
      ans = min(ans, i - it->second);
      it->second = i;
    }
  }
  if (ans == (int)1e9) ans = -1;
  return ans;
}
void build_tree(int v, int bl, int br) {
  if (bl == br) {
    tree[v] = ar[bl];
  } else {
    int bm = (bl + br) / 2;
    build_tree(v + v, bl, bm);
    build_tree(v + v + 1, bm + 1, br);
    tree[v] = func(bl, br);
  }
}
int sum(int v, int bl, int br, int l, int r) {
  if (bl == l && br == r) return tree[v];
  int bm = (bl + br) / 2;
  if (r <= bm) {
    return sum(v + v, bl, bm, l, r);
  } else if (l > bm) {
    return sum(v + v + 1, bm + 1, br, l, r);
  } else {
    return sum(v + v, bl, bm, l, bm) + sum(v + v + 1, bm + 1, br, bm + 1, r);
  }
}
int main() {
  int n, T, m;
  double c;
  cin >> n >> T >> c;
  vector<long long> orig(n + 1);
  vector<long long> v(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &orig[i]);
    v[i] = orig[i] + v[i - 1];
  }
  vector<double> approx_vector(n + 1);
  for (int i = 1; i <= n; i++) {
    approx_vector[i] = (approx_vector[i - 1] + (double)orig[i] / T) / c;
  }
  cin >> m;
  cout << fixed << setprecision(6);
  for (int i = 0; i < m; i++) {
    int zap;
    scanf("%d", &zap);
    double real = (v[zap] - v[zap - T]) / T;
    double approx = approx_vector[zap];
    double error = fabs(approx - real) / real;
    cout << real << " " << approx << " " << error << endl;
  }
  return 0;
}
