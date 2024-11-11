#include <bits/stdc++.h>
using namespace std;
long long int n, m;
pair<long long int, long long int> sol(0, 0);
void maximiza(pair<long long int, long long int> nextsol) {
  if (nextsol.first > sol.first) {
    sol = nextsol;
  } else if (nextsol.first == sol.first) {
    sol.second += nextsol.second;
  }
}
long long int cuenta(map<long long int, long long int> &s) {
  long long int c = 0;
  for (map<long long int, long long int>::iterator it = s.begin();
       it != s.end(); it++)
    c += it->second;
  return c;
}
void genera(map<long long int, long long int> &s0,
            map<long long int, long long int> &s1) {
  long long int n0 = cuenta(s0);
  long long int n1 = cuenta(s1);
  if (n0 <= 1) return;
  long long int min0 = (s0.begin())->first;
  long long int nmin0 = (s0.begin())->second;
  long long int max0 = (--(s0.end()))->first;
  long long int nmax0 = (--(s0.end()))->second;
  if (n1 == 0) {
    if (min0 == max0) {
      maximiza(
          pair<long long int, long long int>(0, n0 * (n0 - 1) * (n0 - 2) / 6));
      return;
    }
    maximiza(pair<long long int, long long int>(
        max0 - min0, nmin0 * (nmin0 - 1) / 2 * nmax0 +
                         nmin0 * nmax0 * (nmax0 - 1) / 2 +
                         nmin0 * nmax0 * (n0 - nmin0 - nmax0)));
    return;
  }
  long long int min1 = (s1.begin())->first;
  long long int nmin1 = (s1.begin())->second;
  long long int max1 = (--(s1.end()))->first;
  long long int nmax1 = (--(s1.end()))->second;
  if (max1 < min0) {
    maximiza(pair<long long int, long long int>(
        max1 + n - min0,
        nmax1 * nmin0 * (nmin0 - 1) / 2 + nmax1 * nmin0 * (n0 - nmin0)));
    return;
  }
  if (max0 < min1) {
    maximiza(pair<long long int, long long int>(
        max0 + n - min1,
        nmin1 * nmax0 * (nmax0 - 1) / 2 + nmin1 * nmax0 * (n0 - nmax0)));
    return;
  }
  map<long long int, long long int>::iterator it0 = s0.begin();
  map<long long int, long long int>::iterator it1 = s1.begin();
  while (it1 != s1.end() and it1->first < it0->first) it1++;
  long long int acum = 0;
  long long int c = 0;
  long long int v0 = 0;
  while (it0 != s0.end() and it1 != s1.end()) {
    if (it0->first < it1->first) {
      acum += c * it0->second;
      v0 += it0->second;
      it0++;
    } else if (it1->first < it0->first) {
      c += v0 * it1->second;
      it1++;
    } else {
      c += v0 * it1->second;
      acum +=
          c * it0->second + it0->second * (it0->second - 1) / 2 * it1->second;
      c += it0->second * it1->second;
      v0 += it0->second;
      it0++;
      it1++;
    }
  }
  while (it0 != s0.end()) {
    acum += c * it0->second;
    it0++;
  }
  maximiza(pair<long long int, long long int>(n, acum));
}
void escribe(map<long long int, long long int> &s) {
  for (map<long long int, long long int>::iterator it = s.begin();
       it != s.end(); it++)
    cout << "(" << it->first << "," << it->second << ")";
  cout << endl;
}
map<long long int, long long int> s[2];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    s[x][y]++;
  }
  genera(s[0], s[1]);
  genera(s[1], s[0]);
  cout << sol.second << endl;
}
