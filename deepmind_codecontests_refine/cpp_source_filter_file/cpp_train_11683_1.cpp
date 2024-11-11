#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
void count_sort(vector<pair<long long, int> >& b, int bits) {
  int mask = (1 << bits) - 1;
  for (int it = 0; it < (2); ++it) {
    int move = it * bits;
    vector<int> q(1 << bits), w((int)(q).size() + 1);
    for (int i = 0; i < ((int)(b).size()); ++i)
      q[(b[i].first >> move) & mask]++;
    partial_sum(q.begin(), q.end(), w.begin() + 1);
    vector<pair<long long, int> > res(b.size());
    for (int i = 0; i < ((int)(b).size()); ++i)
      res[w[(b[i].first >> move) & mask]++] = b[i];
    swap(b, res);
  }
}
struct SuffixArray {
  vector<int> a;
  string s;
  SuffixArray(const string& _s) : s(_s + '\0') {
    int N = (int)(s).size();
    vector<pair<long long, int> > b(N);
    a.resize(N);
    for (int i = 0; i < (N); ++i) {
      b[i].first = s[i];
      b[i].second = i;
    }
    int q = 8;
    while ((1 << q) <= N) q++;
    for (int moc = 0;; moc++) {
      count_sort(b, q);
      a[b[0].second] = 0;
      for (int i = 1; i < (N); ++i)
        a[b[i].second] = a[b[i - 1].second] + (b[i - 1].first != b[i].first);
      if ((1 << moc) >= N) break;
      for (int i = 0; i < (N); ++i) {
        b[i].first = (long long)a[i] << q;
        if (i + (1 << moc) < N) b[i].first += a[i + (1 << moc)];
        b[i].second = i;
      }
    }
    for (int i = 0; i < ((int)(a).size()); ++i) a[i] = b[i].second;
  }
  vector<int> lcp() {
    int n = (int)(a).size(), h = 0;
    vector<int> inv(n), res(n);
    for (int i = 0; i < (n); ++i) inv[a[i]] = i;
    for (int i = 0; i < (n); ++i)
      if (inv[i] > 0) {
        int p0 = a[inv[i] - 1];
        while (s[i + h] == s[p0 + h]) h++;
        res[inv[i]] = h;
        if (h > 0) h--;
      }
    return res;
  }
};
SuffixArray* SA;
int tams[limN];
int tamsAcum[limN];
char* strs[limN];
int buscaPos(int ini, int fin, int dep) {
  char ref = strs[ini][dep];
  while (ini < fin) {
    int piv = (ini + fin) / 2 + 1;
    if (dep < tams[piv] && ref == strs[piv][dep])
      ini = piv;
    else
      fin = piv - 1;
  }
  return ini;
}
char ans[limN];
void calcaOrd(long long pos) {
  int ini = 1, fin = SA->s.size() - 1;
  long long dep = 0;
  long long orgPos = pos;
  while (pos > 0 && ini <= fin) {
    int w = buscaPos(ini, fin, dep);
    if (w > limN || ini <= 0) {
      printf("WTF mango\n");
      exit(0);
    }
    long long k = tamsAcum[w] - tamsAcum[ini - 1] - dep * (w - ini + 1LL);
    if (k < pos) {
      pos -= k;
      ini = w + 1;
    } else {
      if (dep >= tams[ini]) {
        printf("WTF mang\n");
        exit(0);
      }
      ans[dep] = strs[ini][dep];
      dep++;
      fin = w;
      pos -= (fin - ini + 1);
    }
  }
  if (dep == 0) {
    printf("Wat %lld\n", orgPos);
  }
  ans[dep] = 0;
  printf("%s\n", ans);
}
int main() {
  char str[limN];
  long long n;
  int k;
  scanf("%s", str);
  SA = new SuffixArray(str);
  n = SA->s.size() - 1;
  for (int i = 1; i <= n; i++) {
    tams[i] = n - SA->a[i];
    strs[i] = str + SA->a[i];
    tamsAcum[i] = tams[i] + tamsAcum[i - 1];
  }
  scanf("%d", &k);
  if (k > (n * (n + 1)) / 2)
    printf("No such line.\n");
  else
    calcaOrd(k);
}
