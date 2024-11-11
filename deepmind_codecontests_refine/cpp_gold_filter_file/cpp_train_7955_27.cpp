#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cout << (fixed) << setprecision(9);
  int n;
  while (cin >> n) {
    if (n == 5) {
      cout << "3 5 1" << endl;
      cout << "4 5 2" << endl;
      cout << "2 4 1" << endl;
      cout << "1 2 1" << endl;
      cout << "1 3" << endl;
      cout << "2 3" << endl;
      continue;
    }
    int half = n / 2;
    vector<pair<pair<int, int>, int> > edges;
    for (int i = (1), _b = (half); i <= _b; i++)
      edges.push_back(make_pair(make_pair(i, i + half), 1));
    for (int i = (half + 1), _b = (n - 1); i <= _b; i++)
      edges.push_back(make_pair(make_pair(i, i + 1), (i - half) * 2 - 1));
    for (auto e : edges)
      cout << e.first.first << ' ' << e.first.second << ' ' << e.second << endl;
    for (int i = (1), _b = (half - 1); i <= _b; i++)
      cout << i << ' ' << i + 1 << endl;
    cout << "1 3" << endl;
  }
  return 0;
}
