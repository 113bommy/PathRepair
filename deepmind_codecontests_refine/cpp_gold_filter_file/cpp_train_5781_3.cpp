#include <bits/stdc++.h>
using namespace std;
const long long OO = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double pi = 3.14159265359;
void skrrrt() { ios_base::sync_with_stdio(0), cin.tie(0); }
const int N = 2009;
int n, d;
long long mem[N][N][2][2];
string a, b;
long long solve(int ind, int sum, int bgra, int smlrb) {
  if (ind == a.size()) return (sum == 0);
  long long &ret = mem[ind][sum][bgra][smlrb];
  if (~ret) return ret;
  ret = 0;
  for (int i = '0'; i <= '9'; i++) {
    if ((ind % 2) ^ ((i - '0') == d)) continue;
    if (!bgra && i < a[ind]) continue;
    if (!smlrb && i > b[ind]) continue;
    ret = (ret + solve(ind + 1, (sum * 10 + (i - '0')) % n,
                       bgra || (i > a[ind]), smlrb || (i < b[ind]))) %
          mod;
  }
  return ret;
}
int main() {
  skrrrt();
  cin >> n >> d;
  cin >> a >> b;
  memset(mem, -1, sizeof mem);
  cout << solve(0, 0, 0, 0);
}
