#include <bits/stdc++.h>
using namespace std;
void morir() {
  cout << -1 << endl;
  exit(0);
}
long long int sol = 0;
long long int mcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return mcd(a % b, b);
}
void chino(long long int a, long long int b, long long int &ca,
           long long int &cb, long long int d) {
  if (b == 0) {
    ca = d / a;
    cb = 0;
    return;
  }
  chino(b, a % b, cb, ca, d);
  cb = cb - ca * (a / b);
}
long long int chinoclase(long long int clase, long long int x, long long int n,
                         long long int m, long long int mc) {
  long long int cm, cn;
  chino(m, -n, cm, cn, x - clase);
  long long int desp = n / mc;
  if (cm < 0) {
    cm %= desp;
    if (cm < 0) cm += desp;
  } else
    cm %= desp;
  return cm;
}
void calcula(map<long long int, long long int> &mapa, set<long long int> &s,
             long long int clase, long long int n, long long int m,
             long long int mc) {
  if (int(mapa.size()) == 0) morir();
  vector<pair<long long int, long long int> > v;
  set<long long int> se;
  for (map<long long int, long long int>::iterator it = mapa.begin();
       it != mapa.end(); it++) {
    long long int x = it->first;
    long long int t = it->second;
    long long int saltos = chinoclase(clase, x, n, m, mc);
    v.push_back(pair<long long int, long long int>(saltos, t));
    if (s.count(x)) se.insert(saltos);
  }
  sort(v.begin(), v.end());
  vector<pair<long long int, long long int> > w;
  long long int tope = n / mc;
  for (int i = 0; i < int(v.size()); i++) {
    w.push_back(v[i]);
    long long int d = v[i].first;
    long long int inext = (i + 1) % int(v.size());
    long long int dnext = v[inext].first;
    if ((d + 1) % tope != dnext) {
      long long int dprev = (dnext - 1 + tope) % tope;
      w.push_back(pair<long long int, long long int>(dprev, -1));
      if (dprev < w[0].first)
        for (int j = int(w.size()) - 1; j > 0; j--) swap(w[j], w[j - 1]);
    }
  }
  vector<int> contagiado(int(w.size()), 0);
  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int> >,
                 greater<pair<long long int, long long int> > >
      q;
  for (int i = 0; i < int(w.size()); i++)
    if (w[i].second >= 0)
      q.push(pair<long long int, long long int>(w[i].second, i));
  while (not q.empty()) {
    pair<long long int, long long int> p = q.top();
    q.pop();
    long long int t = p.first;
    long long int ind = p.second;
    if (contagiado[ind]) continue;
    if (se.count(ind) == 0) sol = max(sol, t);
    contagiado[ind] = 1;
    int nextind = (ind + 1) % int(w.size());
    q.push(pair<long long int, long long int>(
        t + (w[nextind].first - w[ind].first + tope) % tope * m, nextind));
  }
}
void calcula(long long int n, vector<long long int> v, long long int nv,
             long long int m, vector<long long int> w, long long int nw) {
  long long int mc = mcd(n, m);
  if (mc > nv + nw) morir();
  vector<map<long long int, long long int> > clase(mc);
  vector<set<long long int> > inicial(mc);
  for (int i = 0; i < nv; i++) {
    long long int x = v[i];
    clase[x % mc][x] = x;
    inicial[x % mc].insert(x);
  }
  for (int i = 0; i < nw; i++) {
    long long int y = w[i];
    if (clase[y % mc].count(y % n) == 0) {
      clase[y % mc][y % n] = y;
    }
  }
  for (int i = 0; i < mc; i++) calcula(clase[i], inicial[i], i, n, m, mc);
}
int main() {
  ios::sync_with_stdio(false);
  long long int n, m;
  cin >> n >> m;
  long long int nv;
  cin >> nv;
  vector<long long int> v(nv);
  for (int i = 0; i < nv; i++) cin >> v[i];
  sort(v.begin(), v.end());
  long long int nw;
  cin >> nw;
  vector<long long int> w(nw);
  for (int i = 0; i < nw; i++) cin >> w[i];
  sort(w.begin(), w.end());
  calcula(n, v, nv, m, w, nw);
  calcula(m, w, nw, n, v, nv);
  cout << sol << endl;
}
