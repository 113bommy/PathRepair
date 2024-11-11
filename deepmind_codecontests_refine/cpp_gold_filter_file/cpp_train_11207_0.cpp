#include <bits/stdc++.h>
using namespace std;
bool eq(double a, double b) { return (abs(a - b) < 0.0000001); }
int main(int argc, char* argv[]) {
  int n, w, m;
  cin >> n >> w >> m;
  cout.precision(9);
  double p = double(n * w) / m;
  int t = 0;
  double k;
  double c = w;
  vector<map<int, double> > r;
  bool fail = false;
  for (int i = 0; i < m; i++) {
    k = p;
    map<int, double> q;
    while (!eq(k, 0)) {
      double l = min(k, c);
      if (!eq(c, w) && !eq(c, l)) {
        fail = true;
        break;
      }
      k -= l;
      c -= l;
      q.insert(pair<int, double>(t + 1, l));
      if (eq(c, 0)) {
        c = w;
        t++;
      }
    }
    if (fail) break;
    r.push_back(q);
  }
  if (!fail) {
    cout << "YES" << endl;
    for (vector<map<int, double> >::iterator i = r.begin(); i != r.end(); i++) {
      for (map<int, double>::iterator v = i->begin(); v != i->end(); v++) {
        cout << v->first << " " << v->second << " ";
      }
      cout << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
