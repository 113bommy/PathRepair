#include <bits/stdc++.h>
using namespace std;
struct wierz {
  int pocz, kon, val;
  long long hash;
  wierz *lsyn, *psyn;
};
struct drzewo {
  wierz *wsk;
};
vector<long long> pierwsze;
drzewo ojc[100003];
void change(wierz *w, int pocz, int kon, int val, long long hash, wierz *lsyn,
            wierz *psyn) {
  w->pocz = pocz;
  w->kon = kon;
  w->val = val;
  w->hash = hash;
  w->lsyn = lsyn;
  w->psyn = psyn;
}
wierz *podlacz[2][131072][20];
int logarytm[262150];
wierz *PODL(int x, int pocz, int kon) {
  return podlacz[x][pocz][logarytm[kon - pocz + 1]];
}
long long hasze_jed[2][263000];
long long HASZ(int dl, int x) { return hasze_jed[x][dl]; }
bool lisc(wierz *w) { return (w->pocz == w->kon); }
int dlugosc(wierz *w) { return w->kon - w->pocz + 1; }
bool caly(wierz *w, int x) {
  if (w->val == 0 && x == 0) return 1;
  if (w->val == dlugosc(w) && x == 1) return 1;
  return 0;
}
void prepare(wierz *w) {
  if (lisc(w)) return;
  if (w->lsyn == NULL) {
    w->lsyn = new wierz;
    w->psyn = new wierz;
    int s = (w->pocz + w->kon) / 2;
    change(w->lsyn, w->pocz, s, 0, 13, NULL, NULL);
    change(w->psyn, s + 1, w->kon, 0, 13, NULL, NULL);
  }
  if (caly(w, 0)) {
    change(w->lsyn, w->lsyn->pocz, w->lsyn->kon, 0, HASZ(dlugosc(w->lsyn), 0),
           w->lsyn->lsyn, w->lsyn->psyn);
    change(w->psyn, w->psyn->pocz, w->psyn->kon, 0, HASZ(dlugosc(w->psyn), 0),
           w->psyn->lsyn, w->psyn->psyn);
  }
  if (caly(w, 1)) {
    change(w->lsyn, w->lsyn->pocz, w->lsyn->kon, dlugosc(w->lsyn),
           HASZ(dlugosc(w->lsyn), 1), w->lsyn->lsyn, w->lsyn->psyn);
    change(w->psyn, w->psyn->pocz, w->psyn->kon, dlugosc(w->psyn),
           HASZ(dlugosc(w->psyn), 1), w->psyn->lsyn, w->psyn->psyn);
  }
}
wierz *zamien(int p, int k, wierz *w, int x) {
  wierz *nowy = new wierz;
  *nowy = *w;
  if (w->pocz == p && w->kon == k) {
    nowy = PODL(x, nowy->pocz, nowy->kon);
    return nowy;
  }
  int sr = (w->pocz + w->kon) / 2;
  if (p > sr) {
    nowy->psyn = zamien(p, k, w->psyn, x);
  }
  if (k <= sr) {
    nowy->lsyn = zamien(p, k, w->lsyn, x);
  }
  if (p <= sr && k > sr) {
    nowy->lsyn = zamien(p, sr, w->lsyn, x);
    nowy->psyn = zamien(sr + 1, k, w->psyn, x);
  }
  nowy->val = nowy->lsyn->val + nowy->psyn->val;
  nowy->hash = nowy->lsyn->hash * pierwsze[logarytm[dlugosc(nowy)]] +
               nowy->psyn->hash * pierwsze[logarytm[dlugosc(nowy)] + 20];
  return nowy;
}
int wartosc(wierz *w, int poz) {
  if (lisc(w)) return w->val;
  int s = (w->pocz + w->kon) / 2;
  if (poz <= s)
    return wartosc(w->lsyn, poz);
  else
    return wartosc(w->psyn, poz);
}
int lewe_zero(wierz *w) {
  if (lisc(w)) {
    if (w->val == 0)
      return w->pocz;
    else
      return -1;
  }
  if (!caly(w->lsyn, 1)) return lewe_zero(w->lsyn);
  if (!caly(w->psyn, 1)) return lewe_zero(w->psyn);
  return -1;
}
int pierw_zero(int poz, wierz *w) {
  wierz *gdzie = NULL;
  while (w->pocz != poz || w->kon != poz) {
    int s = (w->pocz + w->kon) / 2;
    if (poz <= s && !caly(w->psyn, 1)) gdzie = w->psyn;
    if (poz <= s)
      w = w->lsyn;
    else
      w = w->psyn;
  }
  if (w->val == 0) return w->pocz;
  if (gdzie == NULL) return -1;
  return lewe_zero(gdzie);
}
string wypisz(int x) {
  string s;
  for (int i = 0; i < 17; i++) s += '0' + wartosc(ojc[x].wsk, i);
  return s;
}
void zwieksz(int id, int pot) {
  int zero = pierw_zero(pot, ojc[id].wsk);
  if (zero > pot) ojc[id].wsk = zamien(pot, zero - 1, ojc[id].wsk, 0);
  ojc[id].wsk = zamien(zero, zero, ojc[id].wsk, 1);
}
int licz;
bool wiekszy(wierz *w1, wierz *w2) {
  if (lisc(w1)) return (w1->val > w2->val);
  if (caly(w1, 1) || caly(w2, 0)) return 1;
  if (caly(w1, 0) || caly(w2, 1)) return 0;
  if (w1->hash == w2->hash) return 0;
  if (w1->psyn->hash != w2->psyn->hash) return wiekszy(w1->psyn, w2->psyn);
  return wiekszy(w1->lsyn, w2->lsyn);
}
bool spr(string a, string b) {
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] > b[i]) return 1;
    if (a[i] < b[i]) return 0;
  }
  return 0;
}
bool comp(int w1, int w2) {
  bool wyn = wiekszy(ojc[w1].wsk, ojc[w2].wsk);
  return wyn;
}
void kazdy(wierz *w, int x) {
  podlacz[x][w->pocz][logarytm[dlugosc(w)]] = w;
  if (lisc(w)) return;
  prepare(w);
  kazdy(w->lsyn, x);
  kazdy(w->psyn, x);
}
void przygotuj(int start) {
  ojc[start].wsk = new wierz;
  change(ojc[start].wsk, 0, 131071, 0, HASZ(131072, 0), NULL, NULL);
  kazdy(ojc[start].wsk, 0);
  ojc[100002].wsk = new wierz;
  change(ojc[100002].wsk, 0, 131071, 131072, HASZ(131072, 1), NULL, NULL);
  kazdy(ojc[100002].wsk, 1);
}
void ini(int start) {
  przygotuj(start);
  for (int i = 0; i <= 100000; i++) ojc[i].wsk = ojc[start].wsk;
}
vector<pair<int, int> > v[100000];
bool odw[100000];
class identyfikator {
 public:
  int wart;
};
bool operator>(identyfikator a, identyfikator b) {
  return comp(a.wart, b.wart);
}
bool operator==(identyfikator a, identyfikator b) { return (a.wart == b.wart); }
bool operator<(identyfikator a, identyfikator b) {
  return (!(a > b) && !(a == b));
}
identyfikator iden(int x) {
  identyfikator a;
  a.wart = x;
  return a;
}
int pop[100000];
bool cp(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void generuj_hasze() {
  int pot = 1, wyn = 0;
  while (1) {
    logarytm[pot] = wyn;
    if (pot == 262144) break;
    pot = pot * 2;
    wyn++;
  }
  for (int i = 1000; i < 2000; i++)
    if (cp(i)) pierwsze.push_back(i);
  long long a = 13, b = 17, dl = 1;
  for (int i = 0; i < 19; i++) {
    hasze_jed[0][dl] = a;
    hasze_jed[0][dl] = b;
    dl = dl * 2;
    a = a * pierwsze[logarytm[dl]] + a * pierwsze[logarytm[dl] + 20];
    b = b * pierwsze[logarytm[dl]] + b * pierwsze[logarytm[dl] + 20];
  }
}
int main() {
  licz = 0;
  generuj_hasze();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  ini(s);
  set<identyfikator> SET;
  SET.insert(iden(s));
  odw[s] = 1;
  while (SET.size()) {
    int w = (*SET.begin()).wart;
    SET.erase(SET.begin());
    for (int i = 0; i < v[w].size(); i++) {
      ojc[100001].wsk = ojc[w].wsk;
      zwieksz(100001, v[w][i].second);
      if (!odw[v[w][i].first] || comp(v[w][i].first, 100001)) {
        if (SET.find(iden(v[w][i].first)) != SET.end())
          SET.erase(iden(v[w][i].first));
        ojc[v[w][i].first].wsk = ojc[100001].wsk;
        pop[v[w][i].first] = w;
        SET.insert(iden(v[w][i].first));
        odw[v[w][i].first] = 1;
      }
    }
  }
  if (!odw[t]) {
    cout << "-1\n";
    return 0;
  }
  long long wyn = 0, pot = 1, mod = 1000000007;
  for (int i = 0; i < 100030; i++) {
    wyn += pot * wartosc(ojc[t].wsk, i);
    wyn = wyn % mod;
    pot = (pot * 2) % mod;
  }
  cout << wyn << "\n";
  vector<int> sciezka;
  int akt = t, akt2;
  while (1) {
    sciezka.push_back(akt);
    if (akt == s) break;
    akt = pop[akt];
  }
  cout << sciezka.size() << "\n";
  for (int i = sciezka.size() - 1; i >= 0; i--) cout << sciezka[i] + 1 << " ";
  cout << "\n";
}
