#include <bits/stdc++.h>
using namespace std;
map<long long, long long> incoada;
queue<pair<long long, long long>> coada;
vector<long long> sol;
int main() {
  long long n, m, x, i, f;
  long long rez = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> x;
    incoada[x]++;
    coada.push({x, 0});
  }
  while (m) {
    f = coada.front().first;
    if (f + 1 <= 2e9 && m && !incoada[f + 1]) {
      rez += coada.front().second + 1;
      m--;
      incoada[f + 1]++;
      sol.push_back(f + 1);
      coada.push({f + 1, coada.front().second + 1});
    }
    if (f - 1 >= -2e9 && m && !incoada[f - 1]) {
      rez += coada.front().second + 1;
      m--;
      incoada[f - 1]++;
      sol.push_back(f - 1);
      coada.push({f - 1, coada.front().second + 1});
    }
    coada.pop();
  }
  cout << rez << "\n";
  for (auto x : sol) {
    cout << x << " ";
  }
  return 0;
}
