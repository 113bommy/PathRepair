#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.X << ", " << pair.Y << ")";
}
long long nwd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (b == 0) {
    return a;
  }
  return nwd(b, a % b);
}
struct p {
  long long x, y, den;
  p(long long _x = 0, long long _y = 0, long long _den = 1) {
    long long gcd = nwd(_x, nwd(_y, _den));
    x = _x / gcd;
    y = _y / gcd;
    den = _den / gcd;
  }
};
p sum(p a, p b, int zn) {
  return p(a.x * b.den + zn * b.x * a.den, a.y * b.den + zn * b.y * a.den,
           a.den * b.den);
}
bool cmp(p a, p b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.den < b.den;
}
bool cmppair(pair<p, p> a, pair<p, p> b) {
  if (cmp(a.first, b.first) || cmp(b.first, a.first))
    return cmp(a.first, b.first);
  return cmp(a.second, b.second);
}
const int N = 2005;
const int M = 1e9 + 7;
p pkt[N];
long long pot[N];
vector<pair<p, p> > sumy;
vector<int> pom;
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    swap(b, c);
    pkt[i] = p(a * c * d * d, b * c * c * d, a * a * d * d + b * b * c * c);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      p incl = sum(pkt[i], pkt[j], -1);
      if (incl.x < 0 || (incl.x == 0 && incl.y < 0)) {
        incl.x *= -1;
        incl.y *= -1;
      }
      long long gcd = nwd(incl.x, incl.y);
      incl.x /= gcd;
      incl.y /= gcd;
      incl.den = 1;
      sumy.push_back(make_pair(sum(pkt[i], pkt[j], 1), incl));
    }
  }
  sort((sumy).begin(), (sumy).end(), cmppair);
  pot[0] = 1;
  for (int i = 1; i < N; i++) {
    pot[i] = 2 * pot[i - 1] % M;
  }
  int act = 1;
  long long res = 0;
  int licz = 1;
  for (int i = 0; i < ((int)(sumy).size()); i++) {
    if (i == ((int)(sumy).size()) - 1 ||
        cmp(sumy[i].first, sumy[i + 1].first)) {
      long long il = 1;
      pom.push_back(licz);
      for (int j = 0; j < ((int)(pom).size()); j++) {
        il *= (pom[j] + 1);
        il %= M;
      }
      res += M + il - act - 1;
      res %= M;
      act = 1;
      licz = 1;
      pom.clear();
    } else {
      if (cmp(sumy[i].second, sumy[i + 1].second)) {
        pom.push_back(licz);
        licz = 1;
      } else {
        licz++;
      }
      act++;
    }
  }
  cout << res << endl;
  return 0;
}
