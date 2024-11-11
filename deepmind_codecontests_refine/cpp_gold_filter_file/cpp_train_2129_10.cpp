#include <bits/stdc++.h>
using namespace std;
const string pocetno = "0000000000";
const string oznake = "RGBYW";
const int maxn = 105;
int N, razlicite, sol = maxn * maxn;
vector<pair<int, int> > V;
set<string> S;
void rijesi() {
  for (int maska = 0; maska < (1 << 10) + 1; maska++) {
    S.clear();
    int tmp = 0;
    for (int i = 0; i < 10; i++)
      if (maska & (1 << i)) tmp++;
    for (int i = 0; i < N; i++) {
      string stanje = pocetno;
      for (int j = 0; j < 5; j++) {
        if (maska & (1 << j) && V[i].first == j) stanje[j] = '1';
        if (maska & (1 << (j + 5)) && V[i].second == j) stanje[j + 5] = '1';
      }
      S.insert(stanje);
    }
    if (S.size() == razlicite) sol = min(sol, tmp);
  }
  printf("%d\n", sol);
}
void ucitaj() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    V.push_back(make_pair(oznake.find(s[0]), s[1] - '0' - 1));
    S.insert(s);
  }
  razlicite = S.size();
}
int main(void) {
  ucitaj();
  rijesi();
  return 0;
}
