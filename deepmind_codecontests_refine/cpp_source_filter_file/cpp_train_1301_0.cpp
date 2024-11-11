#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, niza[100001], broj, brojac, kraj, i;
  vector<int> nova;
  cin >> n >> m;
  brojac = 0;
  kraj = 0;
  for (i = 0; i < n; i++) {
    cin >> niza[i];
    broj = niza[i] / 10;
    broj = (broj + 1) * 10;
    kraj = kraj + niza[i] / 10;
    if (broj - niza[i] < 10) {
      nova.push_back(broj - niza[i]);
    }
    if (niza[i] <= 90) {
      if (niza[i] % 10 == 0) {
        brojac = brojac + (100 - niza[i]) / 10;
      } else {
        brojac = brojac + ((100 - niza[i]) / 10 - 1);
      }
    }
  }
  vector<int>::iterator it;
  sort(nova.begin(), nova.end());
  for (it = nova.begin(); it != nova.end(); ++it) {
    if (m >= *it) {
      kraj++;
      m = m - (*it);
    } else {
      cout << kraj;
      return 0;
      break;
    }
  }
  if (m > 0) {
    if (m / 10 > brojac)
      kraj = kraj + brojac;
    else
      kraj = kraj + m / 10;
  }
  cout << kraj;
  return 0;
}
