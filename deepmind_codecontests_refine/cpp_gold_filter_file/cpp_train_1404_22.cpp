#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, con = 0;
  cin >> n >> m;
  vector<pair<int, int>> ins(n);
  vector<int> rta;
  for (int i = 0; i < n; i++) {
    cin >> ins[i].first;
    ins[i].second = i + 1;
  }
  sort(ins.begin(), ins.end());
  int suma = 0, i = 0;
  while (suma + ins[i].first <= m && i < n) {
    suma += ins[i].first;
    rta.push_back(ins[i].second);
    con++;
    i++;
  }
  cout << con << endl;
  for (auto x : rta) {
    cout << x << " ";
  }
}
