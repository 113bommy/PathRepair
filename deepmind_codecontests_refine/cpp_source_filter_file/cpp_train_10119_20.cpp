#include <bits/stdc++.h>
using namespace std;
class Permutations {
 public:
  vector<vector<int>> numbers;
  vector<int> cols;
  void solve(istream &in, ostream &out) {
    int n, k;
    in >> n >> k;
    cols.resize(k);
    for (int i = 0; i < k; i++) {
      cols[i] = i;
    }
    numbers.resize(n);
    string s;
    for (int i = 0; i < n; i++) numbers[i].resize(k);
    for (int i = 0; i < n; i++) {
      in >> s;
      for (int j = 0; j < k; j++) numbers[i][j] = s.at(j);
    }
    int ans = 200000000;
    do {
      int min1 = 200000000, max1 = -1;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          string s1 = "", s2 = "";
          for (int k1 = 0; k1 < k; k1++) {
            s1 += numbers[i][cols[k1]];
            s2 += numbers[j][cols[k1]];
          }
          int c1 = atoi(s1.c_str());
          int c2 = atoi(s2.c_str());
          if (c1 < c2) swap(c1, c2);
          min1 = min(c2, min1);
          max1 = max(c1, max1);
        }
      }
      ans = min(ans, max1 - min1);
    } while (next_permutation(cols.begin(), cols.end()));
    out << ans << endl;
  }
};
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  filebuf fb;
  fb.open("D:\\QtPro\\CodeForces\\Permutations\\in3.txt", ios_base::in);
  istream &in(cin);
  ostream &out(cout);
  Permutations solver;
  solver.solve(in, out);
  return 0;
}
