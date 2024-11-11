#include <bits/stdc++.h>
using namespace std;
bool check(vector<bool> &a) {
  for (auto i = (0) - ((0) > ((int)(a).size()));
       i != ((int)(a).size()) - ((0) > ((int)(a).size()));
       ((0) < ((int)(a).size()) ? i++ : i--)) {
    if (a[i] == false) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  std::vector<bool> b(n, false), g(m, false);
  int bn;
  cin >> bn;
  for (auto i = (0) - ((0) > (bn)); i != (bn) - ((0) > (bn));
       ((0) < (bn) ? i++ : i--)) {
    int tmp;
    cin >> tmp;
    b[tmp] = true;
  }
  int gm;
  cin >> gm;
  for (auto i = (0) - ((0) > (gm)); i != (gm) - ((0) > (gm));
       ((0) < (gm) ? i++ : i--)) {
    int tmp;
    cin >> tmp;
    g[tmp] = true;
  }
  for (auto i = (0) - ((0) > (23 * max(n, m)));
       i != (23 * max(n, m)) - ((0) > (23 * max(n, m)));
       ((0) < (23 * max(n, m)) ? i++ : i--)) {
    if (b[i % n] == true && g[i % m] == false) {
      g[i % m] = true;
    } else if (b[i % n] == false && g[i % m] == true) {
      b[i % n] = true;
    }
  }
  check(b) && check(g) ? cout << "Yes\n" : cout << "No\n";
  return 0;
}
