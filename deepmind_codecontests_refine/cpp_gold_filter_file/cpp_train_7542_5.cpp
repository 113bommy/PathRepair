#include <bits/stdc++.h>
using namespace std;
int mod(int i, int p) { return (i + p) % p; }
string w[6];
char chess[50][50];
bool check(int perm[]) {
  int n = w[perm[3]].length();
  int m = w[perm[2]].length();
  if (n - 2 < w[perm[0]].length()) {
    return false;
  }
  if (!(w[perm[1]][0] == w[perm[0]][0] && w[perm[1]].length() <= m - 2)) {
    return false;
  }
  if (w[perm[0]].back() != w[perm[2]][0]) {
    return false;
  }
  string w1 = w[perm[1]];
  string w0 = w[perm[0]];
  string w3 = w[perm[3]];
  string w2 = w[perm[2]];
  if (!(w[perm[1]].back() == w3[0] &&
        w3[w[perm[0]].length() - 1] == w2[w[perm[1]].length() - 1])) {
    return false;
  }
  string w4 = w[perm[4]];
  string w5 = w[perm[5]];
  if (!((w4[0] == w3.back() && (w4.length() + w1.length()) == (m + 1)))) {
    return false;
  }
  if (!(w2.back() == w5[0] && w5.back() == w4.back() &&
        w0.length() + w5.length() == (n + 1))) {
    return false;
  }
  return true;
}
vector<string> best;
vector<string> place(const int perm[]) {
  memset(chess, '.', sizeof(chess));
  int n = w[perm[3]].length();
  int m = w[perm[2]].length();
  string w0 = w[perm[0]];
  string w1 = w[perm[1]];
  string w2 = w[perm[2]];
  for (int i = 0; i < w[perm[0]].length(); i++) {
    chess[0][i] = w[perm[0]][i];
  }
  for (int i = 0; i < w[perm[1]].length(); i++) {
    chess[i][0] = w[perm[1]][i];
  }
  for (int i = 0; i < w[perm[2]].length(); i++) {
    chess[i][w0.length() - 1] = w[perm[2]][i];
  }
  for (int i = 0; i < w[perm[3]].length(); i++) {
    chess[w1.length() - 1][i] = w[perm[3]][i];
  }
  for (int i = 0; i < w[perm[4]].length(); i++) {
    chess[w1.length() - 1 + i][n - 1] = w[perm[4]][i];
  }
  for (int i = 0; i < w[perm[5]].length(); i++) {
    chess[m - 1][w0.length() - 1 + i] = w[perm[5]][i];
  }
  vector<string> vs;
  for (int i = 0; i < m; ++i) {
    string s = "";
    for (int j = 0; j < n; ++j) {
      s += chess[i][j];
    }
    vs.push_back(s);
  }
  return vs;
}
bool larger(vector<string> &best, vector<string> &res) {
  int n = best.size();
  int m = res.size();
  int i = 0;
  for (; i < min(n, m); i++) {
    if (res[i] != best[i]) {
      return res[i] < best[i];
    }
  }
  if (i < n) {
    return true;
  }
  return false;
}
int main() {
  for (int i = 0; i < 6; ++i) {
    cin >> w[i];
  }
  int perm[] = {0, 1, 2, 3, 4, 5};
  do {
    if (check(perm)) {
      vector<string> res = place(perm);
      if (best.empty() || larger(best, res)) {
        best = res;
      }
    }
  } while (next_permutation(perm, perm + 6));
  if (best.empty()) {
    cout << "Impossible" << endl;
  } else {
    for (int i = 0; i < best.size(); i++) {
      cout << best[i] << endl;
    }
  }
  return 0;
}
