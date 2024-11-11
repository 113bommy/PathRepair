#include <bits/stdc++.h>
using namespace std;
int D, m, x, y;
vector<vector<long double>> e;
const long double oo = 1.23232323e9;
vector<long double> mns(vector<long double> a, vector<long double> b) {
  vector<long double> ret;
  ret.resize(D);
  for (int i = 0; i < D; i++) ret[i] = a[i] - b[i];
  return ret;
}
vector<long double> tms(vector<long double> a, long double c) {
  for (int i = 0; i < D; i++) a[i] *= c;
  return a;
}
vector<long double> perp(vector<long double> a, vector<long double> b) {
  long double norma = 0, normb = 0, dot = 0;
  for (int i = 0; i < D; i++) {
    norma += a[i] * a[i];
    normb += b[i] * b[i];
    dot += a[i] * b[i];
  }
  norma = pow(norma, 0.5), normb = pow(normb, 0.5);
  if (normb < 1e-13) return a;
  long double tmp = dot / normb / normb;
  vector<long double> bb = tms(b, tmp);
  return mns(a, bb);
}
struct subspace {
  vector<vector<long double>> vectors;
  vector<long long> canon;
  subspace(vector<vector<long double>> _vectors) {
    int d = _vectors.size();
    vectors = _vectors;
    for (int i = 0; i < d; i++)
      for (int j = 0; j < i; j++) vectors[i] = perp(vectors[i], vectors[j]);
    for (int i = 0; i < D + 1; i++) {
      vector<long double> x = e[i];
      for (int j = 0; j < d; j++) x = perp(x, vectors[j]);
      long double norm = 0;
      for (int j = 0; j < D; j++) norm += x[j] * x[j];
      norm = pow(norm, 0.5);
      canon.push_back(oo * norm + 0.314159265);
    }
  }
};
map<vector<long long>, int> mp;
int cnt = 1;
int main() {
  std::ios::sync_with_stdio(false);
  srand(time(0));
  cin >> m >> D;
  e.resize(D + 1);
  for (int i = 0; i < D; i++) {
    e[i].resize(D);
    e[i][i] = 1;
    e[D].push_back(rand() % 232323);
  }
  for (int i = 1; i <= m; i++) {
    vector<vector<long double>> tmp;
    cin >> x;
    for (int j = 0; j < x; j++) {
      vector<long double> v;
      for (int k = 0; k < D; k++) {
        cin >> y;
        v.push_back(y);
      }
      tmp.push_back(v);
    }
    vector<long long> c = subspace(tmp).canon;
    if (mp.count(c))
      cout << mp[c] << " ";
    else
      cout << (mp[c] = cnt++) << " ";
  }
  cout << endl;
}
