#include <bits/stdc++.h>
using namespace std;
string names[1000] = {"Anka",   "Chapay", "Cleo",       "Troll",
                      "Dracul", "Snowy",  "Hexadecimal"};
int v(string s) {
  for (int i = 0; i < (int)(10); i++)
    if (strcmp(names[i].c_str(), s.c_str()) == 0) return i;
}
char as[1000], bs[1000];
vector<pair<int, int> > ad;
long long e[1000];
int p[1000] = {0, 1, 2, 3, 4, 5, 6};
long long team[1000];
long long tot[1000];
char non[1000];
int pm[1000] = {0, 1, 2};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%s%s%s", as, non, bs);
    int a = v(string(as));
    int b = v(string(bs));
    ad.push_back(make_pair(a, b));
  }
  for (int i = 0; i < (int)(3); i++) {
    cin >> e[i];
  }
  long long mxl = 0;
  long long mnd = 2e6;
  do {
    do {
      for (int t3 = 0; t3 < (int)(7); t3++)
        for (int t2 = 0; t2 < (int)(t3); t2++) {
          if (t2 == 0) continue;
          for (int i = 0; i < (int)(7); i++) {
            if (i < t2)
              team[p[i]] = 0;
            else if (i < t3)
              team[p[i]] = 1;
            else
              team[p[i]] = 2;
          }
          tot[pm[0]] = e[pm[0]] / t2;
          tot[pm[1]] = e[pm[1]] / (t3 - t2);
          tot[pm[2]] = e[pm[2]] / (7 - t3);
          long long mn = 2e9;
          long long mx = 0;
          for (int i = 0; i < (int)(3); i++) {
            mn = min(mn, tot[i]);
            mx = max(mx, tot[i]);
          }
          long long d = mx - mn;
          long long c = 0;
          for (int i = 0; i < (int)(ad.size()); i++)
            if (team[ad[i].first] == team[ad[i].second]) c++;
          if (d < mnd || (d == mnd && mxl < c)) {
            mnd = d;
            mxl = c;
          }
        }
    } while (next_permutation(p, p + 7));
  } while (next_permutation(pm, pm + 3));
  cout << mnd << " " << mxl << endl;
  return 0;
}
