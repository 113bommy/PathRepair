#include <bits/stdc++.h>
using namespace std;
void sieve(vector<int> &s, vector<int> &spf) {
  for (int i = 2; i * i < s.size(); i++) {
    if (s[i] == 1) {
      for (int j = i; j * i < s.size(); j++) {
        if (s[i * j] == 1) spf[i * j] = i;
        s[i * j] = 0;
      }
    }
  }
}
vector<int> fact(vector<int> &spf, int n) {
  vector<int> r;
  while (spf[n] != 1) {
    r.push_back(spf[n]);
    n /= spf[n];
  }
  if (n != 1) r.push_back(n);
  return r;
}
int main() {
  vector<int> spf(pow(10, 6), 1);
  vector<int> s(pow(10, 6), 1);
  sieve(s, spf);
  int n, m;
  cin >> n >> m;
  vector<int> x;
  for (int i = 0; i <= n; i++) x.push_back(0);
  vector<vector<int>> v;
  for (int i = 0; i <= n; i++) {
    vector<int> t;
    v.push_back(t);
  }
  for (int i = 0; i < m; i++) {
    char a;
    int b;
    cin >> a >> b;
    if (a == '+') {
      if (x[b] == 1)
        cout << "Already on" << endl;
      else {
        int f = 1;
        vector<int> h = fact(spf, b);
        for (int i = 0; i < h.size(); i++) {
          if (v[h[i]].size() == 0)
            continue;
          else {
            cout << "Conflict with " << v[h[i]][0] << endl;
            f = 0;
            break;
          }
        }
        if (f) {
          x[b] = 1;
          cout << "Success" << endl;
          for (int i = 0; i < h.size(); i++) {
            v[h[i]].push_back(b);
          }
        }
      }
    } else {
      if (x[b] == 0)
        cout << "Already off" << endl;
      else {
        cout << "Success" << endl;
        vector<int> k;
        k = fact(spf, b);
        for (int i = 0; i < k.size(); i++) {
          v[k[i]].erase(remove(v[k[i]].begin(), v[k[i]].end(), b),
                        v[k[i]].end());
        }
        x[b] = 0;
      }
    }
  }
  return 0;
}
