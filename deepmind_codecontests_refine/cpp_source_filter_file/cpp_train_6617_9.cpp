#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int nmax = 200010;
long long res;
vector<vector<pair<int, int> > > vr;
vector<vector<int> > rs;
int n, n1, n2;
long double el[nmax], rs1, rs2;
int main() {
  cin >> n >> n1 >> n2;
  if (n1 > n2) swap(n1, n2);
  for (int i = 0; i < n; ++i) cin >> el[i];
  sort(el, el + n);
  reverse(el, el + n);
  for (int i = 0; i < n1; ++i) {
    rs1 += el[i];
  }
  rs1 /= n1;
  for (int i = n1; i < n1 + n2; ++i) {
    rs2 += el[i];
  }
  rs2 /= n2;
  printf("%.7f\n", rs1 + rs2);
  return 0;
}
