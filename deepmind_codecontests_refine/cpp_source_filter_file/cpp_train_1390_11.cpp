#include <bits/stdc++.h>
using namespace std;
struct team {
  string name;
  int scored;
  int missed;
  int points;
  int difference;
};
int makeint(string j) {
  int k;
  stringstream ss;
  ss << j;
  ss >> k;
  return k;
}
bool testpoints(team lhs, team rhs) { return lhs.points < rhs.points; }
bool testdifference(team lhs, team rhs) {
  return lhs.difference < rhs.difference;
}
bool testscores(team lhs, team rhs) { return lhs.scored < rhs.scored; }
int absolute(int x) {
  if (x < 0) x *= -1;
  return x;
}
int main() {
  int n, i, k, g, sc1, sc2;
  string mena, skore, tm1, tm2, sk1, sk2;
  cin >> n;
  team noidea[n];
  for (i = 0; i < n; i++) {
    cin >> noidea[i].name;
    noidea[i].points = 0;
    noidea[i].scored = 0;
    noidea[i].missed = 0;
  }
  for (i = 0; i < (n * (n - 1) / 2); i++) {
    cin >> mena >> skore;
    g = 0;
    tm1 = "";
    tm2 = "";
    while (mena.at(g) != '-') {
      tm1 = tm1 + mena.at(g);
      g++;
    }
    g++;
    while (g < mena.length()) {
      tm2 = tm2 + mena.at(g);
      g++;
    }
    sk1 = "";
    sk2 = "";
    g = 0;
    while (skore.at(g) != ':') {
      sk1 = sk1 + skore.at(g);
      g++;
    }
    g++;
    while (g < skore.length()) {
      sk2 = sk2 + skore.at(g);
      g++;
    }
    sc1 = makeint(sk1);
    sc2 = makeint(sk2);
    for (k = 0; k < n; k++) {
      if (tm1 == noidea[k].name) {
        noidea[k].scored += sc1;
        noidea[k].missed += sc2;
        if (sc1 > sc2)
          noidea[k].points += 3;
        else if (sc2 == sc1)
          noidea[k].points++;
      }
      if (tm2 == noidea[k].name) {
        noidea[k].scored += sc2;
        noidea[k].missed += sc1;
        if (sc2 > sc1)
          noidea[k].points += 3;
        else if (sc2 == sc1)
          noidea[k].points++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    noidea[i].difference = -noidea[i].scored - noidea[i].missed;
  }
  sort(noidea, noidea + n, testpoints);
  reverse(noidea, noidea + n);
  i = 0;
  int temp;
  while (i < n) {
    temp = noidea[i].points;
    g = i;
    while (i < n && noidea[i].points == temp) i++;
    sort(noidea + g, noidea + i, testdifference);
  }
  i = 0;
  team crap;
  while (i < n) {
    crap.points = noidea[i].points;
    crap.difference = noidea[i].difference;
    crap.scored = noidea[i].scored;
    g = i;
    while (i < n && crap.points == noidea[i].points &&
           crap.difference == noidea[i].difference)
      i++;
    sort(noidea + g, noidea + i, testscores);
    reverse(noidea + g, noidea + i);
  }
  string winners[n / 2];
  for (i = 0; i < n / 2; i++) {
    winners[i] = noidea[i].name;
  }
  sort(winners, winners + n / 2);
  for (i = 0; i < n / 2; i++) {
    cout << winners[i] << endl;
  }
  return 0;
}
