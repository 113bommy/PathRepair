#include <bits/stdc++.h>
using namespace std;
long long int drz[2 * 131072 + 5];
void akt(long long int a, long long int war) {
  a += 131072 - 1;
  while (a) {
    drz[a] = max(drz[a], war);
    a /= 2;
  }
}
int czyt(long long int a, long long int b) {
  a += 131072 - 1;
  b += 131072 - 1;
  long long int wyn = 0;
  wyn = drz[a];
  wyn = max(wyn, drz[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      wyn = max(wyn, drz[a + 1]);
    }
    if (b % 2 == 1) {
      wyn = max(wyn, drz[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return wyn;
}
struct pkt {
  long long int x;
  long long int y;
  int nr;
};
pkt p[100005];
long long int kier[5];
int k1, k2, l1, l2;
long long int ilow(pkt a, pkt b, pkt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool cmp1(pkt a, pkt b) {
  pkt c;
  c.x = a.x + kier[1];
  c.y = a.y + kier[2];
  long long int bla = ilow(a, c, b);
  if (bla != 0) return bla < 0;
  return b.y < a.y;
}
bool cmp2(pkt a, pkt b) {
  pkt c;
  c.x = a.x + kier[3];
  c.y = a.y + kier[4];
  long long int bla = ilow(a, c, b);
  if (bla != 0)
    return bla > 0;
  else
    return b.x < a.x;
}
pkt nowe[100005];
char buff[100];
bool cmp3(pkt a, pkt b) { return a.y < b.y; }
int main() {
  long long int n;
  cin >> n;
  int f, e;
  char c;
  cin >> kier[1] >> c >> kier[2] >> kier[3] >> c >> kier[4];
  for (int i = 1; i <= n; i++) {
    int zia;
    cin >> p[i].y >> p[i].x;
    p[i].nr = i;
  }
  sort(p, p + 1 + n, cmp2);
  for (int i = 0; i <= n; i++) {
    nowe[p[i].nr].y = i + 1;
    nowe[p[i].nr].nr = p[i].nr;
  }
  sort(p, p + 1 + n, cmp1);
  for (int i = 0; i <= n; i++) {
    nowe[p[i].nr].x = i + 1;
  }
  sort(nowe, nowe + 1 + n, cmp3);
  long long int wynik = 0;
  for (int i = 0; i <= n; i++) {
    long long int cos = czyt(1, nowe[i].x);
    if (nowe[i].nr == 0 || cos > 0) {
      wynik = max(wynik, cos + 1);
      akt(nowe[i].x, cos + 1);
    }
  }
  cout << wynik - 1 << endl;
  return 0;
}
