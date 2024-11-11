#include <bits/stdc++.h>
using namespace std;
int n, m;
double k;
map<string, double> p;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;
    double d;
    cin >> s >> d;
    p[s] += d;
  }
  map<string, double>::iterator d = p.end();
  for (map<string, double>::iterator i = p.begin(); i != p.end(); i++) {
    if (d != p.end()) p.erase(d), d = p.end();
    i->second *= k;
    i->second += 1e-11;
    if (int(i->second) < 100) d = i;
  }
  if (d != p.end()) p.erase(d), d = p.end();
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    p[s] += 0;
  }
  cout << p.size() << endl;
  for (map<string, double>::iterator i = p.begin(); i != p.end(); i++) {
    cout << i->first << ' ' << int(i->second) << endl;
  }
  return 0;
}
