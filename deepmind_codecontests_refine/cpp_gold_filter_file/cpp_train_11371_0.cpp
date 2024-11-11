#include <bits/stdc++.h>
using namespace std;
const int MAX_NM = 1000 * 1000;
int dl;
char S[MAX_NM];
void dodaj(char l, int x) {
  while (x--) {
    dl++;
    S[dl] = l;
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > 4 * n * m - 2 * n - 2 * m) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i < m; i++) {
    dodaj('D', n - 1);
    dodaj('U', n - 1);
    dodaj('R', 1);
  }
  dodaj('D', n - 1);
  for (int i = n; i > 1; i--) {
    dodaj('L', m - 1);
    dodaj('R', m - 1);
    dodaj('U', 1);
  }
  dodaj('L', m - 1);
  vector<pair<char, int> > w;
  char l = S[1];
  int a = 1;
  for (int i = 2; i <= k; i++) {
    if (S[i] != S[i - 1]) {
      w.push_back(make_pair(l, a));
      l = S[i];
      a = 1;
    } else {
      a++;
    }
  }
  w.push_back(make_pair(l, a));
  cout << "YES" << endl;
  cout << w.size() << endl;
  for (pair<char, int> p : w) {
    cout << p.second << " " << p.first << endl;
  }
  return 0;
}
