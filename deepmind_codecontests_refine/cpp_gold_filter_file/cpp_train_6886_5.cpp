#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x, y, a, b, c, d, n2, e, f, g, x1, diri, coef, x2, i, j, r, rasp, par,
    impar, n, mini, maxi, pozmini, pozmaxi, auxa, auxb, lat, plat, nrop, ce, bi,
    ba, k, sum2, sum, h, best;
long long int ll;
vector<int> dq;
char c1, c2;
string s, s2;
pair<int, int> dir[1000];
int v[10000];
double dou;
int main() {
  cin >> a >> b;
  while (b % a == 0) {
    b /= a;
    k++;
  }
  if (b == 1)
    cout << "YES" << '\n' << k - 1;
  else
    cout << "NO" << '\n';
  return 0;
}
