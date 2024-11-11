#include <bits/stdc++.h>
using namespace std;
template <typename C>
void MA(C& a, C b) {
  if (a < b) a = b;
}
template <typename C>
void MI(C& a, C b) {
  if (a > b) a = b;
}
const int P = 1e9 + 7;
int n, k;
bool isl(int a) {
  if (a == 0) return 1;
  return (a % 10 == 4 || a % 10 == 7) && isl(a / 10);
}
int w[102001];
int iw = -1;
map<int, int> m;
long long pot(long long a, long long w) {
  long long r = 1;
  while (w) {
    if (w & 1) {
      r *= a;
      r %= P;
    }
    w /= 2;
    a *= a;
    a %= P;
  }
  return r;
}
long long sil[102001], odw[102001];
long long po(int a, int b) {
  if (a < b || b < 0) return 0;
  return sil[a] * odw[b] % P * odw[a - b] % P;
}
int main() {
  scanf("%d%d", &n, &k);
  sil[0] = 1;
  for (int i = 0; i < n + 1; i++) {
    sil[i + 1] = sil[i] * (i + 1) % P;
  }
  for (int i = 0; i < n + 1; i++) {
    odw[i] = pot(sil[i], P - 2);
  }
  for (int i = 0; i < n; i++) {
    int pom;
    scanf("%d", &pom);
    if (isl(pom)) {
      auto x = m.find(pom);
      if (x != m.end()) {
        w[x->second]++;
      } else {
        iw++;
        m[pom] = iw;
        w[iw] = 1;
      }
    } else {
      iw++;
      w[iw] = 1;
    }
  }
  iw++;
  vector<int> a;
  a.push_back(1);
  int il1 = 0;
  for (int i = 0; i < iw; i++) {
    if (w[i] == 1) {
      il1++;
    } else {
      a.push_back(0);
      vector<int> b;
      b.push_back(1);
      for (int ii = 1; ii < a.size(); ii++) {
        b.push_back((a[ii] + a[ii - 1] * w[i]) % P);
      }
      swap(a, b);
    }
  }
  long long wyn = 0;
  while (a.size() < k + 1) a.push_back(0);
  for (int i = 0; i < k + 1; i++) {
    wyn += po(il1, i) * a[k - i] % P;
  }
  cout << wyn % P << "\n";
}
