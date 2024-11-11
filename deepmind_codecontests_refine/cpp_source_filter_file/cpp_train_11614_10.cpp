#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int cv(int cz, int mv) {
  if (cz < 0) return 0;
  return cz / a + 1;
}
int minnumshurt(vector<int>& zh, int i, vector<int>& nv) {
  if (zh.size() - 2 == i) {
    int res = 0;
    res = max(cv(zh[i - 1], b), res);
    res = max(cv(zh[i], a), res);
    res = max(cv(zh[i + 1], b), res);
    for (int j = 0; j < res; j++) nv.push_back(i);
    return res;
  }
  int res = cv(zh[i - 1], b);
  zh[i - 1] -= res * b;
  zh[i] -= res * a;
  zh[i + 1] -= res * b;
  int minres = minnumshurt(zh, i + 1, nv) + res;
  for (int j = 0; j < res; j++) nv.push_back(i);
  while (zh[i] >= 0) {
    zh[i - 1] -= b;
    zh[i] -= a;
    zh[i + 1] -= b;
    res++;
    vector<int> nnv;
    int cur = minnumshurt(zh, i + 1, nnv) + res;
    if (cur < minres) {
      swap(nnv, nv);
      for (int j = 0; j < res; j++) nv.push_back(i);
      minres = min(cur, minres);
    }
  }
  zh[i - 1] += res * b;
  zh[i] += res * a;
  zh[i + 1] += res * b;
  return minres;
}
int main() {
  cin >> n >> a >> b;
  vector<int> zh(n);
  for (auto& z : zh) cin >> z;
  vector<int> nnv;
  cout << minnumshurt(zh, 1, nnv) << endl;
  for (auto v : nnv) cout << v + 1 << " ";
  return 0;
}
