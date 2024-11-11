#include <bits/stdc++.h>
using namespace std;
vector<int> graf[1000];
vector<pair<int, int> > sol;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "YES\n";
    cout << 2 << " " << 1 << endl << 1 << " " << 2;
    return 0;
  }
  if (n % 2 == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  sol.push_back({1, 2});
  sol.push_back({1, 5});
  sol.push_back({2, 3});
  sol.push_back({2, 4});
  sol.push_back({3, 4});
  sol.push_back({3, 5});
  sol.push_back({4, 5});
  int tr = 5;
  int pomn = n;
  while (pomn > 3) {
    int prvi = tr + 1;
    for (int i = 1; i <= tr; i++) sol.push_back({i, prvi});
    prvi++;
    for (int i = 1; i <= tr; i++) sol.push_back({i, prvi});
    tr += 2;
    pomn -= 2;
  }
  cout << 2 * tr << " " << 2 * sol.size() + 1 << "\n";
  for (auto c : sol) cout << c.first << " " << c.second << "\n";
  for (auto c : sol) cout << c.first + tr << " " << c.second + tr << "\n";
  cout << 1 << " " << tr << "\n";
  return 0;
}
