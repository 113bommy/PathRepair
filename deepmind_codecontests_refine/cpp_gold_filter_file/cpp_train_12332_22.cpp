#include <bits/stdc++.h>
using namespace std;
int s, m, l, xl, xxl, k;
string g[1010];
void dfs(string n) {
  if (n == "S")
    if (s) {
      s--;
      cout << "S" << endl;
    } else if (m) {
      m--;
      cout << "M" << endl;
    } else if (l) {
      l--;
      cout << "L" << endl;
    } else if (xl) {
      xl--;
      cout << "XL" << endl;
    } else if (xxl) {
      xxl--;
      cout << "XXL" << endl;
    }
  if (n == "M")
    if (m) {
      m--;
      cout << "M" << endl;
    } else if (l) {
      l--;
      cout << "L" << endl;
    } else if (s) {
      s--;
      cout << "S" << endl;
    } else if (xl) {
      xl--;
      cout << "XL" << endl;
    } else if (xxl) {
      xxl--;
      cout << "XXL" << endl;
    }
  if (n == "L")
    if (l) {
      l--;
      cout << "L" << endl;
    } else if (xl) {
      xl--;
      cout << "XL" << endl;
    } else if (m) {
      m--;
      cout << "M" << endl;
    } else if (xxl) {
      xxl--;
      cout << "XXL" << endl;
    } else if (s) {
      s--;
      cout << "S" << endl;
    }
  if (n == "XL")
    if (xl) {
      xl--;
      cout << "XL" << endl;
    } else if (xxl) {
      xxl--;
      cout << "XXL" << endl;
    } else if (l) {
      l--;
      cout << "L" << endl;
    } else if (m) {
      m--;
      cout << "M" << endl;
    } else if (s) {
      s--;
      cout << "S" << endl;
    }
  if (n == "XXL")
    if (xxl) {
      xxl--;
      cout << "XXL" << endl;
    } else if (xl) {
      xl--;
      cout << "XL" << endl;
    } else if (l) {
      l--;
      cout << "L" << endl;
    } else if (m) {
      m--;
      cout << "M" << endl;
    } else if (s) {
      s--;
      cout << "S" << endl;
    }
}
int main() {
  cin >> s >> m >> l >> xl >> xxl >> k;
  for (int i = 1; i <= k; i++) cin >> g[i];
  for (int i = 1; i <= k; i++) dfs(g[i]);
  return 0;
}
