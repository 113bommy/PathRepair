#include <bits/stdc++.h>
using namespace std;
const int mx = 4000 + 5;
const int mx1 = 36000;
bool vis[mx1];
map<int, long long int> mapa;
int main() {
  int i, j, k, n;
  long long int a;
  string s;
  cin >> a >> s;
  n = s.size();
  int sum;
  int nint = 0;
  for (i = 0; i < n; i++) {
    sum = 0;
    for (j = i; j < n; j++) {
      sum += s[j] - '0';
      if (mapa.count(sum) == 0)
        mapa[sum] = 1;
      else
        mapa[sum]++;
      nint++;
    }
  }
  long long int ans = 0;
  map<int, long long int>::iterator iti, itj;
  for (iti = mapa.begin(); iti != mapa.end(); iti++) {
    int suma = iti->first;
    if (suma != 0 && a % suma == 0) {
      int b = a / suma;
      if (mapa.count(b) != 0) {
        ans += mapa[suma] * mapa[b];
      }
    }
  }
  if (a == 0) ans = 2 * ans + mapa[0] * mapa[0];
  cout << ans << endl;
  return 0;
}
