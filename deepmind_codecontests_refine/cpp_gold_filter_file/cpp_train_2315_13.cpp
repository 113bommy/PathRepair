#include <bits/stdc++.h>
using namespace std;
int n;
string cad;
vector<int> ansp;
vector<int> ansn;
void dothemath(int from, int to, int n0, int n1) {
  if (n0 + 2 < n1) {
    ansp.push_back(n - from);
    ansn.push_back(n - to);
    for (int i = from; i < to; i++)
      if (cad[i] == '0') ansn.push_back(n - i - 1);
  } else {
    for (int i = from; i < to; i++)
      if (cad[i] == '1') ansp.push_back(n - i - 1);
  }
}
int main() {
  cin >> cad;
  n = cad.size();
  int from = 0, n0 = 0, n1 = 1;
  for (int i = 0; i < n; i++) {
    if (cad[i] == '0') {
      if (i == n - 1 || cad[i + 1] == '0') {
        dothemath(from, i, n0, n1);
        while (i < n && cad[i] == '0') i++;
        from = i;
        n0 = 0;
        n1 = 1;
      } else
        n0++;
    } else
      n1++;
  }
  if (from < n) dothemath(from, n, n0, n1);
  cout << ansp.size() + ansn.size() << '\n';
  for (int i = 0; i < ansn.size(); i++) cout << "-2^" << ansn[i] << '\n';
  for (int i = 0; i < ansp.size(); i++) cout << "+2^" << ansp[i] << '\n';
  return 0;
}
