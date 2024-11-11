#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18 + 7;
vector<bool> prmc(1000010, true);
vector<long long int> prime;
const long long int N = 1000010;
int fp[N];
void sieve(int n) {
  prmc[0] = prmc[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (prmc[i]) {
      for (int j = i * i; j <= n; j += i) prmc[j] = false;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (prmc[i]) prime.push_back(i);
  }
}
void smallestprime(long long int n) {
  for (long long int i = 2; i < n; i++) {
    if (fp[i] == 0) {
      prime.push_back(i);
      for (long long int j = i; j < n; j += i) {
        if (fp[j] == 0) fp[j] = i;
      }
    }
  }
}
inline long long int modpw(long long int x, long long int y, long long int z) {
  long long int res = 1;
  x = x % z;
  while (y) {
    if (y & 1) res = (res * x) % z;
    x = (x * x) % z;
    y /= 2;
  }
  return res;
}
long long int gcd(long long int ct, long long int b) {
  if (b == 0) return ct;
  return gcd(b, ct % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int t;
  cin >> t;
  double chi = 0.00000001;
  while (t--) {
    double d;
    cin >> d;
    if (d == 0) {
      cout << "Y " << d << " " << d << endl;
      continue;
    }
    if (d < 4) {
      cout << "N\n";
      continue;
    }
    double l = 0, r = d, md, md1;
    int flag = 0;
    while (r >= l) {
      flag++;
      md = (r + l) / 2, md1 = d - md;
      if (fabs(md * md1 - d) <= chi) {
        flag = -1;
        cout << "Y " << md << " " << md1 << endl;
        break;
      }
      if (md * md1 < d) l = md;
      if (md * md1 > d) r = md;
      if (flag == 400) break;
    }
    if (flag != -1) {
      cout << "Y " << md << " " << md1 << endl;
    }
  }
  return 0;
}
