#include <bits/stdc++.h>
using namespace std;
struct pkt {
  int x, y;
};
pkt ja, cien;
set<pair<int, int> > Z;
int n;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
string odp = "";
int Spr() {
  stack<pkt> S;
  set<pair<int, int> > odw;
  S.push(ja);
  odw.insert(make_pair(ja.x, ja.y));
  bool wyj = false;
  while (!S.empty()) {
    pkt akt = S.top();
    S.pop();
    if (akt.x == 101 || akt.x == -101 || akt.y == 101 || akt.y == -101)
      wyj = true;
    for (int i = 0; i < 4; ++i) {
      pkt nowy = {akt.x + dx[i], akt.y + dy[i]};
      if (Z.find(make_pair(nowy.x, nowy.y)) == Z.end() &&
          odw.find(make_pair(nowy.x, nowy.y)) == odw.end() && nowy.x >= -101 &&
          nowy.x <= 101 && nowy.y >= -101 && nowy.y <= 101) {
        S.push(nowy);
        odw.insert(make_pair(nowy.x, nowy.y));
      }
    }
  }
  if (odw.find(make_pair(cien.x, cien.y)) == odw.end()) return 0;
  if (wyj) return 1;
  return 2;
}
bool Wew(pkt a) {
  return (a.x >= -100 && a.x <= 100 && a.y >= -100 && a.y <= 100);
}
void P(int x, int y) {
  for (int i = 0; i < abs(x); ++i) {
    if (x > 0) {
      odp += "R";
      ++ja.x;
      if (Z.find(make_pair(cien.x + 1, cien.y)) == Z.end()) ++cien.x;
    } else {
      odp += "L";
      --ja.x;
      if (Z.find(make_pair(cien.x - 1, cien.y)) == Z.end()) --cien.x;
    }
  }
  for (int i = 0; i < abs(y); ++i) {
    if (y > 0) {
      odp += "U";
      ++ja.y;
      if (Z.find(make_pair(cien.x, cien.y + 1)) == Z.end()) ++cien.y;
    } else {
      odp += "D";
      --ja.y;
      if (Z.find(make_pair(cien.x, cien.y - 1)) == Z.end()) --cien.y;
    }
  }
}
void Wyjdz(pkt start) {
  queue<pkt> Q;
  set<pair<int, int> > odw;
  map<pair<int, int>, pair<int, int> > pop;
  Q.push(start);
  odw.insert(make_pair(start.x, start.y));
  pop[make_pair(start.x, start.y)] = make_pair(1000, 1000);
  pkt akt;
  while (!Q.empty()) {
    akt = Q.front();
    Q.pop();
    if (akt.x == 101 || akt.x == -101 || akt.y == 101 || akt.y == -101) break;
    for (int i = 0; i < 4; ++i) {
      pkt nowy = {akt.x + dx[i], akt.y + dy[i]};
      if (Z.find(make_pair(nowy.x, nowy.y)) == Z.end() &&
          odw.find(make_pair(nowy.x, nowy.y)) == odw.end() && nowy.x >= -101 &&
          nowy.x <= 101 && nowy.y >= -101 && nowy.y <= 101) {
        odw.insert(make_pair(nowy.x, nowy.y));
        Q.push(nowy);
        pop[make_pair(nowy.x, nowy.y)] = make_pair(akt.x, akt.y);
      }
    }
  }
  string path = "";
  while (true) {
    pkt ost = {pop[make_pair(akt.x, akt.y)].first,
               pop[make_pair(akt.x, akt.y)].second};
    if (ost.x == 1000) break;
    if (akt.x == ost.x) {
      if (akt.y > ost.y)
        path += "U";
      else
        path += "D";
    } else {
      if (akt.x > ost.x)
        path += "R";
      else
        path += "L";
    }
    akt = ost;
  }
  reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); ++i) {
    if (path[i] == 'U') P(0, 1);
    if (path[i] == 'D') P(0, -1);
    if (path[i] == 'L') P(-1, 0);
    if (path[i] == 'R') P(1, 0);
  }
}
void Obracaj(pkt a) {
  if (a.x >= 101) return;
  if (a.y >= 101) {
    P(101 - a.x, 101 - a.y);
    return;
  }
  if (a.x <= -101) {
    P(-101 - a.x, 101 - a.y);
    P(202, 0);
    return;
  }
  P(101 - a.x, -101 - a.y);
  P(0, 202);
}
string bfs() {
  queue<pkt> Q;
  set<pair<int, int> > odw;
  map<pair<int, int>, pair<int, int> > pop;
  Q.push(ja);
  odw.insert(make_pair(ja.x, ja.y));
  pop[make_pair(ja.x, ja.y)] = make_pair(1000, 1000);
  while (!Q.empty()) {
    pkt akt = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      pkt nowy = {akt.x + dx[i], akt.y + dy[i]};
      if (Z.find(make_pair(nowy.x, nowy.y)) == Z.end() &&
          odw.find(make_pair(nowy.x, nowy.y)) == odw.end()) {
        odw.insert(make_pair(nowy.x, nowy.y));
        Q.push(nowy);
        pop[make_pair(nowy.x, nowy.y)] = make_pair(akt.x, akt.y);
      }
    }
  }
  string path = "";
  pkt akt = cien;
  while (true) {
    pkt ost = {pop[make_pair(akt.x, akt.y)].first,
               pop[make_pair(akt.x, akt.y)].second};
    if (ost.x == 1000) break;
    if (akt.x == ost.x) {
      if (akt.y > ost.y)
        path += "U";
      else
        path += "D";
    } else {
      if (akt.x > ost.x)
        path += "R";
      else
        path += "L";
    }
    akt = ost;
  }
  reverse(path.begin(), path.end());
  return path;
}
int main() {
  cin >> ja.x >> ja.y >> cien.x >> cien.y;
  cin >> n;
  pkt g = {0, -101}, d = {0, 101}, p = {-101, 0}, l = {101, 0};
  for (int i = 0; i < n; ++i) {
    pkt t;
    cin >> t.x >> t.y;
    if (t.y > g.y) g = t;
    if (t.y < d.y) d = t;
    if (t.x > p.x) p = t;
    if (t.x < l.x) l = t;
    Z.insert(make_pair(t.x, t.y));
  }
  if (n == 0 || Spr() == 0) {
    cout << "-1";
    return 0;
  }
  if (Spr() == 1) {
    if (Wew(ja)) Wyjdz(ja);
    Obracaj(ja);
    P(1000, 0);
    if (Wew(cien)) Wyjdz(cien);
    Obracaj(cien);
    if (ja.x != cien.x) {
      if (cien.x < ja.x) {
        P(p.x + 1 - cien.x, p.y - cien.y);
        P(cien.x - ja.x, 0);
      } else {
        if (ja.y <= cien.y) {
          P(101 - ja.x, 101 - ja.y);
          P(-101 - cien.x, 0);
        } else {
          P(101 - ja.x, -101 - ja.y);
          P(-101 - cien.x, 0);
        }
        P(l.x - 1 - cien.x, l.y - cien.y);
        P(cien.x - ja.x, 0);
      }
    }
    if (ja.y != cien.y) {
      if (cien.y < ja.y) {
        if (ja.x > p.x)
          P(101 - cien.x, 101 - cien.y);
        else
          P(-101 - cien.x, 101 - cien.y);
        P(g.x - cien.x, g.y + 1 - cien.y);
      } else {
        if (ja.x > p.x)
          P(101 - cien.x, -101 - cien.y);
        else
          P(-101 - cien.x, -101 - cien.y);
        P(d.x - cien.x, d.y - 1 - cien.y);
      }
      P(0, cien.y - ja.y);
    }
  } else {
    string path = bfs();
    queue<int> Q;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == 'U') Q.push(0);
      if (path[i] == 'R') Q.push(1);
      if (path[i] == 'D') Q.push(2);
      if (path[i] == 'L') Q.push(3);
    }
    while (!Q.empty()) {
      if (Q.front() == 0) odp += "U";
      if (Q.front() == 1) odp += "R";
      if (Q.front() == 2) odp += "D";
      if (Q.front() == 3) odp += "L";
      ja = {ja.x + dx[Q.front()], ja.y + dy[Q.front()]};
      pkt nowyCien = {cien.x + dx[Q.front()], cien.y + dy[Q.front()]};
      if (Z.find(make_pair(nowyCien.x, nowyCien.y)) == Z.end()) {
        cien = nowyCien;
        Q.push(Q.front());
      }
      if (ja.x == cien.x && ja.y == cien.y) break;
      Q.pop();
    }
  }
  cout << odp;
  return 0;
}
