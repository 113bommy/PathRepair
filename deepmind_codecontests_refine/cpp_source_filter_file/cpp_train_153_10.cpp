#include <bits/stdc++.h>
using namespace std;
string a[1000];
vector<string> Q;
int main() {
  int tol = 0, sum = 0;
  while (getline(cin, a[tol++]))
    ;
  for (int i = 0; i < tol; i++) {
    string tmp = "";
    if (a[i][0] == '+') {
      for (int j = 1; j < a[i].size(); j++) tmp += a[i][j];
      Q.push_back(tmp);
    } else if (a[i][0] == '-') {
      for (int j = 1; j < a[i].size(); j++) tmp += a[i][j];
      int l = Q.size();
      for (int j = 0; j < l; j++)
        if (Q[j] == tmp) {
          Q.erase(Q.begin() + j);
          break;
        }
    } else {
      int ans = a[i].size();
      int tol = 0;
      while (a[i][tol] != ':') {
        tol++;
      }
      tol++;
      sum += (ans - tol) * Q.size();
    }
  }
  printf("%d\n", sum);
}
