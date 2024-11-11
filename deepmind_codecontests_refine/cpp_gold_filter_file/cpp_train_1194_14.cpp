#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int r, i;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long int power(long long int x, long long int y, long long int mod) {
  long long int temp, ty, my;
  if (y == 0) return 1;
  temp = power(x, y / 2, mod);
  ty = (temp % mod) * (temp % mod);
  if (y % 2 == 0) {
    return ty % mod;
  } else {
    my = (x % mod) * (ty % mod);
    return my % mod;
  }
}
long long int maxi(long long int a, long long int b) { return a > b ? a : b; }
long long int maxx(long long int a, long long int b, long long int c,
                   long long int d, long long int e) {
  return maxi(maxi(maxi(a, b), maxi(c, d)), e);
}
struct abhi {
  long long int val;
  long long int pos;
};
struct abhi brr[100010];
bool cmp(struct abhi x, struct abhi y) { return x.pos < y.pos; }
char ss[100010];
long long int ar[100100];
long long int b[100100];
vector<pair<int, int> > abhi;
int main() {
  ios_base::sync_with_stdio(false);
  long long int t, m, i, n, r, j, k = 0, p, kk = 0;
  cin >> n;
  string s;
  cin >> s;
  k = s.size();
  char po = s[0];
  int cc = 0;
  for (i = (0); i < (k); i++) {
    if (s[i] == po) cc++;
  }
  int cn[6];
  cn[0] = 0;
  cn[1] = 0;
  cn[2] = 0;
  cn[3] = 0;
  for (i = 0; i < k; i++) {
    if (s[i] == 'A')
      cn[0]++;
    else if (s[i] == 'C') {
      cn[1]++;
    } else if (s[i] == 'G') {
      cn[2]++;
    } else {
      cn[3]++;
    }
  }
  sort(cn, cn + 4);
  j = 3;
  long long int cnt = 0;
  long long int big = cn[3];
  j = 3;
  while (j >= 0) {
    if (cn[j] == big) {
      cnt++;
    }
    j--;
  }
  long long int mod = 1000000007;
  cout << power(cnt, n, mod) << "\n";
  return 0;
}
