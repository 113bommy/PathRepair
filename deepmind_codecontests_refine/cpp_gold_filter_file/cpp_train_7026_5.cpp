#include <bits/stdc++.h>
using namespace std;
void yala_bena() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
}
const int m_r = 199999;
double pii = 3.1415926536;
int match(char *s, char *p, int overlap) {
  int c = 0, l = strlen(p);
  while (*s != '\0') {
    if (strncmp(s++, p, l)) continue;
    if (!overlap) s += l - 1;
    c++;
  }
  return c;
}
int main() {
  yala_bena();
  int n, m, a, b;
  long long minn = 1e8;
  map<int, int> m1;
  map<int, vector<int> > mop;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    mop[a].push_back(b);
    mop[b].push_back(a);
    m1[a]++;
    m1[b]++;
  }
  map<int, int>::iterator it = m1.begin();
  for (it; it != m1.end(); it++) {
    if (it->second <= 1) continue;
    vector<int> v = mop[it->first];
    for (int i = 0; i < v.size(); i++) {
      vector<int> v1 = mop[v[i]];
      for (int j = 0; j < v1.size(); j++) {
        vector<int> v2 = mop[v1[j]];
        for (int k = 0; k < v2.size(); k++) {
          if (v2[k] == it->first) {
            if (it->second - 2 + v2.size() - 2 + v1.size() - 2 < minn)
              minn = it->second - 2 + v2.size() - 2 + v1.size() - 2;
          }
        }
      }
    }
  }
  if (minn == 1e8)
    cout << -1 << endl;
  else
    cout << minn << endl;
}
