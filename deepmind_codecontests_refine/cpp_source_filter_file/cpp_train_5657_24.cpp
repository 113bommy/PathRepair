#include <bits/stdc++.h>
using namespace std;
long long cp(const complex<long long>& a, const complex<long long>& b) {
  return a.real() * b.imag() - b.real() * a.imag();
}
struct comp {
  const bool operator()(const complex<long long>& l,
                        const complex<long long>& r) const {
    if (l.imag() == r.imag()) return l.real() < r.real();
    return l.imag() < r.imag();
  }
} cmp_lex_i;
vector<complex<long long> > chull(vector<complex<long long> > p) {
  sort(p.begin(), p.end(), cmp_lex_i);
  int top = 0, bot = 1;
  vector<complex<long long> > ch(2 * p.size());
  for (int i = 0, d = 1; i < p.size() && i >= 0; i += d) {
    while (top > bot && cp(ch[top - 1] - ch[top - 2], p[i] - ch[top - 2]) <= 0)
      top--;
    ch[top++] = p[i];
    if (i == p.size() - 1) d = -1, bot = top;
  }
  ch.resize(max(1, top - 1));
  return ch;
}
int main() {
  int n, m, x, y;
  vector<complex<long long> > p;
  p.reserve(200000);
  set<complex<long long>, comp> B;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    p.push_back(complex<long long>(x, y));
  }
  cin >> m;
  while (m--) {
    cin >> x >> y;
    p.push_back(complex<long long>(x, y));
    B.insert(complex<long long>(x, y));
  }
  p = chull(p);
  bool yes = true;
  for (int i = 0; i < p.size(); i++) {
    if (B.count(p[i])) {
      yes = false;
      break;
    }
  }
  if (yes)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
