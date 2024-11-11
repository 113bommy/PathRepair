#include <bits/stdc++.h>
using namespace std;
long long DIV = 1e9 + 7;
struct data {
  int u, v, h;
};
struct line {
  long long m, b;
  long long ertek(long long x) { return (x * m + b) % DIV; }
  bool operator<(line a) const {
    if (m != a.m) return m < a.m;
    return b < a.b;
  }
};
long long Hatvany(long long n, long long h) {
  if (h == 0) return 1;
  return ((h & 1) ? Hatvany(n * n % DIV, (h >> 1)) * n
                  : Hatvany(n * n % DIV, (h >> 1))) %
         DIV;
}
long long tav[2000] = {}, ujTav[2000] = {};
line buffer[2000];
vector<data> elek;
long long meg = 0;
void MaxTav(int n, int m, int k) {
  ujTav[0] = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) tav[j] = ujTav[j];
    for (int j = 0; j < m; j++) {
      ujTav[elek[j].u] =
          max(ujTav[elek[j].u], tav[elek[j].v] + (long long)elek[j].h);
      ujTav[elek[j].v] =
          max(ujTav[elek[j].v], tav[elek[j].u] + (long long)elek[j].h);
    }
    long long legN = 0;
    for (int j = 0; j < n; j++) legN = max(legN, (long long)ujTav[j]);
    meg = (meg + legN) % DIV;
  }
  for (int i = 0; i < n; i++) tav[i] = ujTav[i];
  return;
}
bool Kell(line &a, line &b, line &c) {
  if ((a.b - c.b) * (c.m - b.m) <= (b.b - c.b) * (c.m - a.m)) return false;
  return true;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 2000; i++) ujTav[i] = -(long long)2e9;
  int n, m;
  long long q;
  cin >> n >> m >> q;
  elek.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> elek[i].u >> elek[i].v >> elek[i].h;
    elek[i].u--;
    elek[i].v--;
  }
  MaxTav(n, m, min(n, (int)q));
  vector<line> lines(m);
  for (int i = 0; i < m; i++)
    lines[i] = {elek[i].h, max(tav[elek[i].u], tav[elek[i].v])};
  sort(lines.begin(), lines.end());
  int veg = 1;
  buffer[0] = lines[0];
  for (int i = 1; i < m; i++) {
    if (lines[i].m == lines[i - 1].m)
      buffer[veg - 1] = lines[i];
    else
      buffer[veg++] = lines[i];
    while (veg > 3 &&
           !Kell(buffer[veg - 1], buffer[veg - 2], buffer[veg - 3])) {
      buffer[veg - 2] = buffer[veg - 1];
      veg--;
    }
  }
  q -= n;
  int ind = 0;
  long long x = 1, oszt = Hatvany(2, DIV - 2);
  while (x <= q) {
    if (ind + 1 == veg) {
      meg = (meg + ((buffer[ind].ertek(x) + buffer[ind].ertek(q)) *
                    (long long)(q - x + 1) % DIV) *
                       oszt % DIV) %
            DIV;
      break;
    }
    long long hely = (buffer[ind + 1].b - buffer[ind].b) /
                     (buffer[ind].m - buffer[ind + 1].m);
    if (x <= hely) {
      hely = min(hely, q);
      meg = (meg + ((buffer[ind].ertek(x) + buffer[ind].ertek(hely)) *
                    (long long)(hely - x + 1) % DIV) *
                       oszt % DIV) %
            DIV;
      x = hely + 1;
    }
    ind++;
  }
  cout << meg << "\n";
  return 0;
}
