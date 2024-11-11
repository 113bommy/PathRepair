#include <bits/stdc++.h>
using namespace std;
int f(string pno) {
  char prev;
  int result;
  bool f = true;
  bool g = true;
  for (int i = 0; i < pno.size(); ++i) {
    if (pno[i] == '-') continue;
    if (i == 0) {
      prev = pno[i];
      continue;
    }
    g = g && (pno[i] == prev);
    f = f && (pno[i] < prev);
    prev = pno[i];
  }
  if (g) result = 0;
  if (f) result = 1;
  if (!f && !g) result = 2;
  return result;
}
int n, num, v[101][3], ans[3], maxv;
string pno, names[101];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num >> names[i];
    for (int j = 0; j < num; ++j) {
      cin >> pno;
      v[i][f(pno)]++;
    }
  }
  vector<vector<int>> amax(3);
  for (int j = 0; j < 3; ++j) {
    maxv = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
      if (v[i][j] > maxv) {
        maxv = v[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (v[i][j] == maxv) {
        amax[j].push_back(i);
      }
    }
  }
  string r = names[amax[0][0]];
  for (int i = 1; i < amax[0].size(); ++i) r = r + ", " + names[amax[0][i]];
  cout << "If you want to call a taxi, you should call: " << r << ".\n";
  r = names[amax[1][0]];
  for (int i = 1; i < amax[1].size(); ++i) r = r + ", " + names[amax[1][i]];
  cout << "If you want to order a pizza, you should call: " << r << ".\n";
  r = names[amax[2][0]];
  for (int i = 1; i < amax[0].size(); ++i) r = r + ", " + names[amax[2][i]];
  cout << "If you want to go to a cafe with a wonderful girl, you should call: "
       << r << ".\n";
  return 0;
}
