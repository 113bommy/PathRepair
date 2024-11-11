#include <bits/stdc++.h>
using namespace std;
struct punct {
  double x;
  double y;
};
struct cerc {
  double x;
  double y;
  double r;
};
cerc v[203];
int n, varfuri, muchii, componente;
int viz[203];
int A[203][203];
set<pair<long long, long long> > S[203], sAll;
inline double pt(double x) { return x * x; }
int identice(cerc a, cerc b) {
  if (a.x == b.x && a.y == b.y && a.r == b.r)
    return 1;
  else
    return 0;
}
pair<long long, long long> normalizare(punct a) {
  pair<long long, long long> b;
  b.first = (long long)(a.x * 10000);
  b.second = (long long)(a.y * 10000);
  return b;
}
int intersect(cerc a, cerc b, punct &p, punct &r) {
  int patratDistantaCentre =
      (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (patratDistantaCentre > (a.r + b.r) * (a.r + b.r)) return 0;
  if (patratDistantaCentre < (a.r - b.r) * (a.r - b.r)) return 0;
  if (patratDistantaCentre == (a.r + b.r) * (a.r + b.r)) {
    p.x = a.x + a.r * (b.x - a.x) / sqrt(patratDistantaCentre);
    p.y = a.y + a.r * (b.y - a.y) / sqrt(patratDistantaCentre);
    return 1;
  }
  if (patratDistantaCentre == (a.r - b.r) * (a.r - b.r)) {
    if (a.r < b.r) {
      cerc aux = a;
      a = b;
      b = aux;
    }
    p.x = a.x + a.r * (b.x - a.x) / sqrt(patratDistantaCentre);
    p.y = a.y + a.r * (b.y - a.y) / sqrt(patratDistantaCentre);
    return 1;
  }
  double A, B, C, X, Y;
  if (a.y == b.y) {
    A = a.r;
    B = b.r;
    C = a.x - b.x;
    if (C < 0) C = -C;
    double P = (A + B + C) / 2;
    double ariaPatrata = P * (P - A) * (P - B) * (P - C);
    Y = 2 * sqrt(ariaPatrata) / C;
    p.y = a.y - Y;
    r.y = a.y + Y;
    X = sqrt(pt(a.r) - pt(Y));
    if (a.x < b.x) {
      p.x = r.x = a.x + X;
    } else {
      p.x = r.x = b.x + X;
    }
    return 2;
  }
  if (a.x == b.x) {
    A = a.r;
    B = b.r;
    C = a.y - b.y;
    if (C < 0) C = -C;
    double P = (A + B + C) / 2;
    double ariaPatrata = P * (P - A) * (P - B) * (P - C);
    X = 2 * sqrt(ariaPatrata) / C;
    p.x = a.x - X;
    r.x = a.x + X;
    Y = sqrt(pt(a.r) - pt(X));
    if (a.y < b.y) {
      p.y = r.y = a.y + Y;
    } else {
      p.y = r.y = b.y + Y;
    }
    return 2;
  }
  A = 2 * a.x - 2 * b.x;
  B = 2 * a.y - 2 * b.y;
  C = pt(b.r) - pt(a.r) + pt(a.x) - pt(b.x) + pt(a.y) - pt(b.y);
  double aa = pt(B) + pt(A);
  double bb = -2 * a.x * pt(B) - 2 * A * C + 2 * a.y * A * B;
  double cc = pt(B) * pt(a.x) + pt(C) - 2 * a.y * B * C + pt(a.y) * pt(B) -
              pt(a.r) * pt(B);
  double delta = (pt(bb) - 4 * aa * cc);
  p.x = (-bb - sqrt(delta)) / (2 * aa);
  r.x = (-bb + sqrt(delta)) / (2 * aa);
  p.y = (C - A * p.x) / B;
  r.y = (C - A * r.x) / B;
  return 2;
}
int cmp(cerc a, cerc b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.r < b.r;
}
void dfs(int nod) {
  viz[nod] = 1;
  for (int i = 1; i <= n; i++)
    if (viz[i] == 0 && A[nod][i] == 1) dfs(i);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].x >> v[i].y >> v[i].r;
  }
  sort(v + 1, v + n + 1, cmp);
  int k = 1;
  for (int i = 2; i <= n; i++)
    if (!identice(v[i], v[k])) {
      v[++k] = v[i];
    }
  n = k;
  punct p;
  punct r;
  pair<long long, long long> P;
  pair<long long, long long> R;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      int nr = intersect(v[i], v[j], p, r);
      if (nr) {
        A[i][j] = A[j][i] = 1;
        P = normalizare(p);
        R = normalizare(r);
        S[i].insert(P);
        S[j].insert(P);
        sAll.insert(P);
        if (nr == 2) {
          S[i].insert(R);
          S[j].insert(R);
          sAll.insert(R);
        }
      }
    }
  varfuri = sAll.size();
  for (int i = 1; i <= n; i++) {
    if (S[i].size() >= 1)
      muchii += S[i].size();
    else {
      muchii++;
      varfuri++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (viz[i] == 0) {
      componente++;
      dfs(i);
    }
  cout << muchii - varfuri + componente + 1;
  return 0;
}
