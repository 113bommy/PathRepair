#include <bits/stdc++.h>
const long long M = 1e9 + 7;
const long long N = 2e5 + 5;
using namespace std;
const double pi = 3.14159265358979323846264338327950;
const long long A = 1e9 + 1;
double esp = 1e-3;
int main() {
  ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> pos, nev;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= 0)
      pos.push_back(x);
    else
      nev.push_back(x);
  }
  sort(pos.begin(), pos.end());
  sort(nev.begin(), nev.end());
  if (pos.size() == 0) {
    cout << nev[nev.size() - 1] << " ";
    for (int i = 1; i < nev.size() - 1; i++) cout << nev[i] << " ";
    cout << nev[0];
  } else if (nev.size() == 0) {
    cout << pos[pos.size() - 1] << " ";
    for (int i = 1; i < pos.size() - 1; i++) cout << pos[i] << " ";
    cout << pos[0];
  } else {
    cout << pos[pos.size() - 1] << " ";
    for (int i = 1; i < nev.size(); i++) cout << nev[i] << " ";
    for (int i = 0; i < pos.size() - 1; i++) cout << pos[i] << " ";
    cout << nev[0];
  }
  cout << endl;
}
