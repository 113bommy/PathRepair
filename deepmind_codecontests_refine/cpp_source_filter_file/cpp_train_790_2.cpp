#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using vi = vector<lli>;
using vvi = vector<vi>;
using pii = tuple<lli, lli>;
using vii = vector<pii>;
using vvii = vector<vii>;
string TYPE(const int*) { return "%d"; }
string TYPE(const lli*) { return "%lld"; }
string TYPE(const char*) { return "%c"; }
string TYPE(const char**) { return "%s"; }
string TYPE(const unsigned int*) { return "%u"; }
const int MAX_BUF = 100 * 1000 + 42;
char buf[MAX_BUF];
void RD() {}
template <typename T, typename... Args>
void RD(T* v, Args... args) {
  scanf((" " + TYPE(v)).c_str(), v);
  RD(args...);
}
template <typename... Args>
void RD(string* v, Args... args) {
  scanf(" %s", buf);
  (*v) = buf;
  RD(args...);
}
void PR(bool nl = true) {
  if (nl) printf("\n");
}
template <typename T, typename... Args>
void PR(bool nl, T v, Args... args) {
  printf((TYPE(&v) + " ").c_str(), v);
  PR(nl, args...);
}
template <typename... Args>
void PR(bool nl, string& v, Args... args) {
  printf("%s", v.c_str());
  PR(nl, args...);
}
template <typename... Args>
void PR(Args... args) {
  PR(true, args...);
}
const long long int oo = 1000 * 1000 * 1000;
struct Coord {
  int x, y;
  Coord(int x = 0, int y = 0) : x(x), y(y) {}
  Coord operator+(const Coord& droite) const {
    return Coord(x + droite.x, y + droite.y);
  }
};
struct AB {
  int k;
  vector<lli> arbre;
  AB(int _k = 20, lli def = 0) {
    k = _k;
    for (lli i = 0; i < (lli)(1 << k); ++i)
      arbre.push_back(i < (1 << (k - 1)) ? 0LL : def);
    for (lli i = (((1 << (k - 1)) - 1)); i >= (lli)(1); --i)
      arbre[i] = arbre[i << 1] + arbre[(i << 1) ^ 1];
  }
  void set(int i, lli x) {
    int feuille = i + (1 << (k - 1));
    arbre[feuille] = x;
    iset(feuille >> 1);
  }
  void iset(int noeud) {
    if (noeud) {
      arbre[noeud] = arbre[noeud << 1] + arbre[(noeud << 1) ^ 1];
      iset(noeud >> 1);
    }
  }
  lli sum(int deb, int fin, int noeud = 1, int p = 0, int q = -1) {
    if (q < p) q = 1 << (k - 1);
    if (deb <= p && q <= fin) return arbre[noeud];
    if (deb >= q || fin <= p) return 0LL;
    int mil = (p + q) / 2;
    return sum(deb, fin, noeud << 1, p, mil) +
           sum(deb, fin, (noeud << 1) ^ 1, mil, q);
  }
};
char buff[42];
set<int> fin[2];
string tmp[2][100 * 1000 + 42];
set<int> swp[2];
set<string> wait[2];
int nb[2];
set<int> dispo;
bool isInt(string s) {
  if (s == "0") return true;
  if (s[0] < '1' || s[0] > '9') return false;
  for (lli i = (1); i <= (lli)(s.length() - 1); ++i)
    if (s[i] < '0' || s[i] > '9') return false;
  return true;
}
vector<string> op;
int main() {
  int n, e = 0;
  RD(&n);
  for (lli i = 0; i < (lli)(n); ++i) {
    int ty;
    scanf(" %s%d", buff, &ty);
    e += ty;
    tmp[ty][nb[ty]++] = buff;
  }
  for (lli i = (1); i <= (lli)(n); ++i) fin[i <= e].insert(i);
  dispo.insert(0);
  for (lli i = (n + 1); i <= (lli)(1E6 - 1); ++i) dispo.insert(i);
  for (lli i = 0; i < (lli)(2); ++i)
    for (lli j = 0; j < (lli)(nb[i]); ++j)
      if (isInt(tmp[i][j])) {
        int x = stoi(tmp[i][j]);
        if (0 < x && x <= e) {
          fin[1].erase(x);
          if (!i) swp[0].insert(x);
        } else if (x <= n) {
          fin[0].erase(x);
          if (i) swp[1].insert(x);
        } else {
          dispo.erase(x);
          wait[i].insert(tmp[i][j]);
        }
      } else
        wait[i].insert(tmp[i][j]);
  for (lli i = 0; i < (lli)(n); ++i)
    for (lli j = 0; j < (lli)(2); ++j) {
      if (fin[j].size() && swp[j].size()) {
        int x = *fin[j].begin();
        int y = *swp[j].begin();
        op.push_back(to_string(y) + " " + to_string(x));
        fin[j].erase(x);
        swp[j].erase(y);
        fin[!j].insert(y);
      }
    }
  if (swp[0].size()) {
    assert(swp[0].size() > 0);
    assert(swp[1].size() > 0);
    int x = *dispo.begin();
    int y = *swp[0].begin();
    op.push_back(to_string(y) + " " + to_string(x));
    dispo.erase(x);
    swp[0].erase(y);
    wait[0].insert(to_string(y));
    fin[1].insert(y);
    for (lli i = 0; i < (lli)(n); ++i)
      for (lli j = 0; j < (lli)(2); ++j) {
        if (fin[j].size() && swp[j].size()) {
          int x = *fin[j].begin();
          int y = *swp[j].begin();
          op.push_back(to_string(y) + " " + to_string(x));
          fin[j].erase(x);
          swp[j].erase(y);
          fin[!j].insert(y);
        }
      }
  }
  for (lli i = 0; i < (lli)(2); ++i) {
    int m = wait[i].size();
    for (lli j = 0; j < (lli)(m); ++j) {
      int x = *fin[i].begin();
      string y = *wait[i].begin();
      op.push_back(y + " " + to_string(x));
      fin[i].erase(x);
      wait[i].erase(y);
    }
  }
  PR((int)op.size());
  for (auto o : op) printf("move %s\n", o.c_str());
  return 0;
}
