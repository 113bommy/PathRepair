#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long c[3][n];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) cin >> c[i][j];
  }
  vector<int> kaimynai[n];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    kaimynai[a].push_back(b);
    kaimynai[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (kaimynai[i].size() >= 3) {
      cout << "-1";
      return 0;
    }
  }
  int pradinis = 0;
  for (int i = 0; i < n; i++) {
    if (kaimynai[i].size() == 1) pradinis = i;
  }
  bool aplankyti[n];
  for (int i = 0; i < n; i++) aplankyti[i] = 0;
  queue<int> eile;
  eile.push(pradinis);
  aplankyti[pradinis] = 1;
  int spalva[n];
  spalva[pradinis] = 0;
  while (!eile.empty()) {
    int g = eile.front();
    eile.pop();
    for (int i = 0; i < kaimynai[g].size(); i++) {
      if (aplankyti[kaimynai[g][i]] == 0) {
        aplankyti[kaimynai[g][i]] = 1;
        eile.push(kaimynai[g][i]);
        spalva[kaimynai[g][i]] = (spalva[g] + 1) % 3;
      }
    }
  }
  long long suma[6];
  for (int i = 0; i < 3; i++) {
    suma[i] = 0;
    for (int j = 0; j < n; j++) suma[i] += c[(spalva[j] + i) % 3][j];
  }
  int spalva1[n];
  spalva1[pradinis] = 0;
  for (int i = 0; i < n; i++) aplankyti[i] = 0;
  aplankyti[pradinis] = 1;
  eile.push(pradinis);
  while (!eile.empty()) {
    int g = eile.front();
    eile.pop();
    for (int i = 0; i < kaimynai[g].size(); i++) {
      if (aplankyti[kaimynai[g][i]] == 0) {
        aplankyti[kaimynai[g][i]] = 1;
        eile.push(kaimynai[g][i]);
        spalva1[kaimynai[g][i]] = (spalva1[g] + 2) % 3;
      }
    }
  }
  for (int i = 3; i < 6; i++) {
    suma[i] = 0;
    for (int j = 0; j < n; j++) suma[i] += c[(spalva1[j] + i) % 3][j];
  }
  long long id = 0, sk = suma[0];
  for (int i = 1; i < 6; i++) {
    if (suma[i] < sk) {
      sk = suma[i];
      id = i;
    }
  }
  cout << suma[id] << endl;
  if (id < 3) {
    for (int i = 0; i < n; i++) cout << 1 + (spalva[i] + id) % 3 << " ";
  } else {
    for (int i = 0; i < n; i++) cout << 1 + (spalva1[i] + id) % 3 << " ";
  }
  return 0;
}
