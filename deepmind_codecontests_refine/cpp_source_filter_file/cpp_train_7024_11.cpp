#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
int n;
string in;
string can = "ACGT";
int main() {
  cin >> n >> in;
  int cont = -1, id = 0;
  for (int i = 0; i < 4; i++) {
    int cn = 0;
    for (int j = 0; j < n; j++)
      if (in[j] == can[i]) cn++;
    if (cn > cont) {
      cont = cn;
      id = 1;
    } else if (cn == cont) {
      id++;
    }
  }
  long long int mod = 1000000007LL;
  long long int ans = 1;
  for (int i = 0; i < id; i++) {
    ans = (ans * ((long long int)n)) % mod;
  }
  cout << ans << endl;
  return 0;
}
