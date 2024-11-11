#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, tmp;
  cin >> n;
  long long res = 0;
  vector<int> v(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> v[i];
  }
  vector<int> vals(n + 10, 0);
  for (int i = 0; i < (int)(n); i++) {
    vals[v[i]]++;
  }
  if (n == 1) {
    cout << "0"
         << "\n";
    ;
    return 0;
  }
  vector<int> ind;
  int par = 0, impar = 0;
  for (int i = 1; i <= (int)(n); i++) {
    if (!vals[i]) {
      if (i % 2) {
        impar++;
      } else {
        par++;
      }
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    if (v[i] != 0) {
      ind.push_back(i);
    }
  }
  if (ind.size() == 0) {
    cout << "1"
         << "\n";
    ;
    return 0;
  }
  int dif = 0;
  vector<int> pp, ii;
  for (int i = 0; i < (int)ind.size() - 1; i++) {
    if (v[ind[i]] % 2 != v[ind[i + 1]] % 2) {
      dif++;
    } else {
      if (ind[i + 1] - ind[i] == 1) {
        continue;
      }
      if (v[ind[i]] % 2 == 1) {
        ii.push_back(ind[i + 1] - ind[i] - 1);
      } else {
        pp.push_back(ind[i + 1] - ind[i] - 1);
      }
    }
  }
  vector<int> pzin, izin;
  sort(pp.begin(), pp.end());
  sort(ii.begin(), ii.end());
  if (v[ind[0]] % 2 == 0 and ind[0] != 0) {
    pzin.push_back(ind[0]);
  } else if (ind[0] != 0) {
    izin.push_back(ind[0]);
  }
  if (v[ind[ind.size() - 1]] % 2 == 0 and ind[ind.size() - 1] != n - 1) {
    pzin.push_back(n - 1 - ind[ind.size() - 1]);
  } else if (ind[ind.size() - 1] != n - 1) {
    izin.push_back(n - 1 - ind[ind.size() - 1]);
  }
  sort(pzin.begin(), pzin.end());
  sort(izin.begin(), izin.end());
  long long total = 0;
  vector<int> s1;
  s1.push_back(par);
  vector<int> r1(pzin.size() + 10, 0);
  if (pzin.size() >= 1 and par - pzin[0] >= 0) {
    s1.push_back(par - pzin[0]);
    r1[1]++;
  }
  if (pzin.size() >= 2 and par - pzin[0] - pzin[1] >= 0) {
    s1.push_back(par - pzin[0] - pzin[1]);
    r1[2] += 2;
  }
  for (int i = 0; i < pp.size(); i++) {
    total += pp[i];
    for (int i = 0; i < (int)(s1.size()); i++) {
      if (total <= s1[i]) {
        r1[i] += 2;
      }
    }
  }
  tmp = 1e8;
  for (int i = 0; i < (int)(s1.size()); i++) {
    r1[i] = pp.size() * 2 + pzin.size() - r1[i];
    tmp = min(tmp, r1[i]);
  }
  res += tmp;
  total = 0;
  vector<int> s2;
  s2.push_back(impar);
  vector<int> r2(izin.size() + 10, 0);
  if (izin.size() >= 1 and impar - izin[0] >= 0) {
    s2.push_back(impar - izin[0]);
    r2[1]++;
  }
  if (izin.size() >= 2 and impar - izin[0] - izin[1] >= 0) {
    s2.push_back(impar - izin[0] - izin[1]);
    r2[2] += 2;
  }
  for (int i = 0; i < ii.size(); i++) {
    total += ii[i];
    for (int i = 0; i < (int)(s2.size()); i++) {
      if (total <= s1[i]) {
        r2[i] += 2;
      }
    }
  }
  tmp = 1e8;
  for (int i = 0; i < s2.size(); i++) {
    tmp = min(tmp, (int)((ii.size() * 2) + izin.size() - r2[i]));
  }
  res += tmp;
  res += dif;
  cout << res << "\n";
  ;
  return 0;
}
