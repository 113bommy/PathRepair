#include <bits/stdc++.h>
using namespace std;
vector<int> p[151];
void pre() {
  p[0] = {1};
  p[1] = {0, 1};
  for (int i = (2); i <= (150); ++i) {
    vector<int> np;
    np.emplace_back(0);
    for (int j = (0); j <= (((int)(p[i - 1]).size()) - 1); ++j)
      np.emplace_back(p[i - 1][j]);
    for (int j = (0); j <= (((int)(p[i - 2]).size())); ++j)
      np[j] = (np[j] + p[i - 2][j]) % 2;
    p[i] = np;
  }
}
void print(int id) {
  for (int i = (0); i <= (((int)(p[id]).size()) - 1); ++i)
    cout << p[id][i] << " \n"[i == ((int)(p[id]).size()) - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  pre();
  int n;
  cin >> n;
  cout << n << '\n';
  print(n);
  cout << n - 1 << '\n';
  print(n - 1);
  return 0;
}
