#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <class T>
string tostring(T a) {
  ostringstream os;
  os << a;
  return os.str();
}
int toint(string a) {
  istringstream is(a);
  int p;
  is >> p;
  return p;
}
long long toll(string a) {
  istringstream is(a);
  long long p;
  is >> p;
  return p;
}
long long count(vector<int> v) {
  vector<vector<long long> > vv(v.size() + 1,
                                vector<long long>(v.size() + 1, 0));
  vv[0][0] = 1;
  for (int i = 1; i <= v.size(); i++) {
    for (int j = 0; j <= i - j - 1; j++) {
      if (v[i - 1] != 1) vv[j][i - j] += vv[j][i - j - 1];
      if (v[i - 1] != -1) vv[j + 1][i - j - 1] += vv[j][i - j - 1];
    }
  }
  return vv[v.size() / 2][v.size() / 2];
}
double count1(vector<int> v) {
  vector<vector<double> > vv(v.size() + 1, vector<double>(v.size() + 1, 0));
  vv[0][0] = 1;
  for (int i = 1; i <= v.size(); i++) {
    for (int j = 0; j <= i - j - 1; j++) {
      if (v[i - 1] != 1) vv[j][i - j] += vv[j][i - j - 1];
      if (v[i - 1] != -1) vv[j + 1][i - j - 1] += vv[j][i - j - 1];
    }
  }
  return vv[v.size() / 2][v.size() / 2] + 0.5;
}
int main() {
  long long m, n, k;
  cin >> m >> n >> k;
  int t;
  vector<int> v(m + n - 1, 20000);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t;
      v[i + j] = min(v[i + j], t);
    }
  }
  vector<pair<int, int> > vp;
  for (int i = 0; i < v.size(); i++) {
    vp.push_back(make_pair(v[i], i));
  }
  sort(vp.begin(), vp.end());
  vector<int> vvvv(vp.size(), 0);
  for (int i = 0; i < vp.size(); i++) {
    vvvv[vp[i].second] = -1;
    long long ct = count(vvvv);
    double ct1 = count(vvvv);
    if (ct1 < 2 * k && ct < k) {
      k -= (long long)ct;
      vvvv[vp[i].second] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vvvv[i + j] == -1)
        cout << "(";
      else
        cout << ")";
    }
    cout << endl;
  }
}
