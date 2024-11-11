#include <bits/stdc++.h>
using namespace std;
vector<int> v[200100];
queue<int> zero;
queue<int> one;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int cont = 0;
  int zi = 0;
  bool ok = true;
  for (auto &x : s) {
    zi++;
    if (x == '0') {
      if (one.empty()) {
        cont++;
        v[cont].push_back(zi);
        zero.push(cont);
      } else {
        int bag = one.front();
        one.pop();
        v[bag].push_back(zi);
        zero.push(bag);
      }
    } else {
      if (zero.empty()) {
        ok = false;
        break;
      } else {
        int bag = zero.front();
        zero.pop();
        v[bag].push_back(zi);
        one.push(bag);
      }
    }
  }
  if (!one.empty()) {
    ok = false;
  }
  if (!ok) {
    cout << -1;
    return 0;
  }
  cout << cont << '\n';
  for (int i = 1; i <= cont; i++) {
    cout << v[i].size() << " ";
    for (auto &x : v[i]) {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}
