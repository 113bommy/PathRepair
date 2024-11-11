#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string X, Y;
long long N, M;
long long SX, SY;
long long Z;
long long cnt[1000 * 1000][26];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  cin >> X >> Y;
  SX = int((X).size());
  SY = int((Y).size());
  long long g = gcd(SX, SY);
  Z = SY / g;
  long long j = 0;
  for (int i = (0); i < (SY); i++) {
    if (j == g) j = 0;
    cnt[j][Y[i] - 'a']++;
    j++;
  }
  long long res = 0;
  j = 0;
  for (int i = (0); i < (SX); i++) {
    if (j == g) j = 0;
    res += Z - cnt[j][X[i] - 'a'];
    j++;
  }
  res *= N * gcd(SX, SY) / SY;
  cout << res << endl;
}
