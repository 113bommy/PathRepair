#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
int t;
bool arr[61][61];
int n, m;
bool nosoln() {
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j)
      if (arr[i][j]) return false;
  return true;
}
bool soln0() {
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j)
      if (!arr[i][j]) return false;
  return true;
}
void copy(bool from[61][61], bool to[61][61]) {
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) to[i][j] = from[i][j];
}
bool soln1() {
  bool all = true;
  for (int i = 0; i < (int)(n); ++i) {
    if (!arr[i][0]) all = false;
  }
  if (all) return true;
  all = true;
  for (int i = 0; i < (int)(n); ++i) {
    if (!arr[i][m - 1]) all = false;
  }
  if (all) return true;
  all = true;
  for (int j = 0; j < (int)(n); ++j) {
    if (!arr[0][j]) all = false;
  }
  if (all) return true;
  all = true;
  for (int j = 0; j < (int)(n); ++j) {
    if (!arr[n - 1][j]) all = false;
  }
  if (all) return true;
  return false;
}
bool soln2() {
  if (arr[0][0] || arr[n - 1][m - 1] || arr[n - 1][0] || arr[0][m - 1])
    return true;
  for (int i = 1; i < (int)(n - 1); i++) {
    bool all = true;
    for (int j = 0; j < (int)(m); ++j) {
      if (!arr[i][j]) all = false;
    }
    if (all) return true;
  }
  for (int j = 1; j < (int)(m - 1); j++) {
    bool all = true;
    for (int i = 0; i < (int)(n); ++i) {
      if (!arr[i][j]) all = false;
    }
    if (all) return true;
  }
  return false;
}
bool soln3() {
  for (int i = 0; i < (int)(n); ++i) {
    if (arr[i][0] || arr[i][m - 1]) return true;
  }
  for (int j = 0; j < (int)(m); ++j) {
    if (arr[0][j] || arr[n - 1][j]) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    char c;
    for (int i = 0; i < (int)(n); ++i)
      for (int j = 0; j < (int)(m); ++j) {
        cin >> c;
        arr[i][j] = c == 'A';
      }
    if (nosoln())
      cout << "MORTAL" << endl;
    else if (soln0())
      cout << "0" << endl;
    else if (soln1())
      cout << "1" << endl;
    else if (soln2())
      cout << "2" << endl;
    else if (soln3())
      cout << "3" << endl;
    else
      cout << "4" << endl;
  }
}
