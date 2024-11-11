#include <bits/stdc++.h>
using namespace std;
size_t ham_dist(const string &a, const string &b) {
  size_t ct = 0;
  for (size_t i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) ++ct;
  return ct;
}
string opp(const string &a) {
  string r = "";
  for (size_t i = 0; i < a.size(); ++i) r += (a[i] == '0' ? "1" : "0");
  return r;
}
string read_line(size_t m) {
  string r;
  for (size_t j = 0; j < m; ++j) {
    char c[2];
    cin >> c;
    r += string(c);
  }
  return r;
}
string string_from_int(size_t len, size_t z) {
  string o;
  for (size_t i = 0; i < len; ++i) {
    if (z & (1 << i))
      o += "1";
    else
      o += "0";
  }
  return o;
}
int main() {
  size_t n, m, k;
  cin >> n >> m >> k;
  map<string, size_t> counts;
  vector<string> mat;
  mat.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    string l = read_line(m);
    mat.push_back(l);
  }
  if (n < m) {
    vector<string> newmat = mat;
    swap(n, m);
    mat.clear();
    mat.reserve(n);
    for (size_t i = 0; i < n; ++i) {
      string p;
      for (size_t j = 0; j < m; ++j) {
        p += newmat[j][i];
      }
      mat.push_back(p);
    }
  }
  for (size_t i = 0; i < n; ++i) {
    string &l = mat[i];
    if (counts.find(l) == counts.end()) counts[l] = 0;
    ++counts[l];
  }
  bool feasible = false;
  if (counts.size() <= 2 * k) {
    if (n < k) {
      for (size_t z = 0; z < ((size_t)1 << m); ++z) {
        string l = string_from_int(m, z);
        if (counts.find(l) == counts.end()) counts[l] = 0;
      }
    }
    for (map<string, size_t>::iterator it = counts.begin(); it != counts.end();
         ++it) {
      size_t cost = 0;
      for (map<string, size_t>::iterator jt = counts.begin();
           jt != counts.end(); ++jt) {
        if (jt->second == 0) continue;
        size_t cost_per = ham_dist(it->first, jt->first);
        cost_per = min(cost_per, ham_dist(opp(it->first), jt->first));
        cost += cost_per * jt->second;
      }
      if (cost <= k) {
        feasible = true;
        k = cost;
      }
    }
  }
  if (!feasible) {
    cout << "-1" << endl;
  } else {
    cout << k << endl;
  }
  return 0;
}
